
#include <ignition/physics.hh>
#include <ignition/plugin/Loader.hh>

using namespace ignition::physics;

struct MyFeatureList : FeatureList<
    GetEntities,
    RemoveEntities,
    ConstructEmptyWorldFeature,
    ConstructEmptyModelFeature,
    ConstructEmptyLinkFeature,
    CollisionFilterMaskFeature,
    FindFreeGroupFeature,
    SetFreeGroupWorldPose,
    SetFreeGroupWorldVelocity,
    GetBasicJointState,
    SetBasicJointState,
    GetBasicJointProperties,
    SetJointTransformFromParentFeature,
    SetJointTransformToChildFeature,
    DetachJointFeature,
    SetFreeJointRelativeTransformFeature,
    AttachFixedJointFeature,
    SetRevoluteJointProperties,
    GetRevoluteJointProperties,
    AttachRevoluteJointFeature,
    SetPrismaticJointProperties,
    GetPrismaticJointProperties,
    AttachPrismaticJointFeature,
    SetJointVelocityCommandFeature,
    LinkFrameSemantics,
    ShapeFrameSemantics,
    FreeGroupFrameSemantics,
    AddLinkExternalForceTorque,
    GetShapeKinematicProperties,
    SetShapeKinematicProperties,
    GetShapeBoundingBox,
    GetBoxShapeProperties,
    AttachBoxShapeFeature,
    GetCylinderShapeProperties,
    AttachCylinderShapeFeature,
    GetSphereShapeProperties,
    ForwardStep,
    GetContactsFromLastStepFeature
> {};

int main()
{
  auto engine = RequestEngine3d<MyFeatureList>::From(
        ignition::plugin::PluginPtr());

  if (engine)
  {
    std::cout << "We have an engine? How??" << std::endl;
    auto world = engine->ConstructEmptyWorld("my world");
    auto model = world->ConstructEmptyModel("my model");
    auto link = model->ConstructEmptyLink("my link");
    auto joint = link->AttachRevoluteJoint(nullptr);
  }
  else
  {
    std::cout << "Whoops, no engine" << std::endl;
  }
}
