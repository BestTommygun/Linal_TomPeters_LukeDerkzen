#include "pch.h"
#include "Renderer.h"

Renderer::Renderer(Camera& camera) :
	camera{ camera }
{
}

System::Collections::Generic::List<RenderLine>^ Renderer::calculateFrame(const std::vector<std::unique_ptr<Object3d>>& toRenderObjects, double screenWidth, double screenHeight)
{
	//get the projection
	const Matrix3d& camMatrix = this->camera.getMatrix();
	const Vector3d& cameraTarget = camMatrix.getPosition() - camMatrix.getBackDirection();
	const Matrix3d& lookAtMatrix = Matrix3d::createLookAt(camMatrix.getPosition(), cameraTarget, Vector3d::yAxis);
	const Matrix3d& projectionMatrix = camera.getPerspectiveMatrix();

	const std::vector<std::unique_ptr<Object3d>>& worldObjectsCopy = toRenderObjects;
	System::Collections::Generic::List<RenderLine>^ returnLines = gcnew System::Collections::Generic::List<RenderLine>();

	size_t worldObjectsCopySize = worldObjectsCopy.size();
	for (size_t i = 0; i < worldObjectsCopySize; i++) {
		auto& curObject = worldObjectsCopy[i];

		Matrix3d curObjectMatrix = curObject->getPosition() * lookAtMatrix;
		std::vector<PointXYW> points;
		//System::Console::WriteLine(System::Math::Round(curObjectMatrix.m41,2) + ":" + System::Math::Round(curObjectMatrix.m42,2) + ":" + System::Math::Round(curObjectMatrix.m43,2) + ":");

		size_t vertexesSize = curObject->getMesh().vertexes.size();
		points.resize(vertexesSize);
		for (size_t j = 0; j < vertexesSize; j++) {
			auto& curVertex = curObject->getMesh().vertexes[j];
			Matrix3d vertexMatrix = (Matrix3d(curVertex) * curObjectMatrix) * projectionMatrix;

			if (vertexMatrix.m43 < camera.getFar() && vertexMatrix.m43 > camera.getNear()) {
				//means it will be rendered
				points[j] = (PointXYW((screenWidth / 2) + ((vertexMatrix.m41 / vertexMatrix.m44) * (screenWidth / vertexMatrix.m44)),
					(screenHeight / 2) + ((vertexMatrix.m42 / vertexMatrix.m44) * (screenHeight / vertexMatrix.m44)), vertexMatrix.m44));
			}
			else {
				//this won't be rendered
				points[j] = (PointXYW((screenWidth / 2) + ((vertexMatrix.m41 / vertexMatrix.m44) * (screenWidth / vertexMatrix.m44)),
					(screenHeight / 2) + ((vertexMatrix.m42 / vertexMatrix.m44) * (screenHeight / vertexMatrix.m44)), -1));
			}
		}
		//convert points to a list of lines
		const Mesh& curObjectMesh = curObject->getMesh();
		const size_t* curTriangle = curObjectMesh.getTriangles();

		size_t trianglesSize = curObject->getMesh().getTrianglesSize();
		for (size_t triangleIndex = 0; triangleIndex < trianglesSize; triangleIndex += 3) {

			//get all triangle points and convert them to lines
			const PointXYW& point1 = points[curTriangle[triangleIndex]];
			const PointXYW& point2	= points[curTriangle[triangleIndex + 1]];
			const PointXYW& point3	= points[curTriangle[triangleIndex + 2]];
			System::Drawing::PointF drawablePoint1 = System::Drawing::PointF(point1.x, point1.y);
			System::Drawing::PointF drawablePoint2 = System::Drawing::PointF(point2.x, point2.y);
			System::Drawing::PointF drawablePoint3 = System::Drawing::PointF(point3.x, point3.y);

			if (point1.w > 0 && point2.w > 0) 
				returnLines->Add(RenderLine(drawablePoint1, drawablePoint2, LineColour::RED));
			if (point2.w > 0 && point3.w > 0)
				returnLines->Add(RenderLine(drawablePoint2, drawablePoint3, LineColour::RED));
			if(point1.w > 0 && point3.w > 0)
				returnLines->Add(RenderLine(drawablePoint3, drawablePoint1, LineColour::RED));
		}

	}

	return returnLines;
}
