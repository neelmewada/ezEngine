#pragma once

#include <EditorEngineProcessFramework/Gizmos/GizmoHandle.h>
#include <EditorFramework/Gizmos/GizmoBase.h>
#include <QPoint>
#include <ToolsFoundation/ToolsFoundationDLL.h>

class EZ_EDITORFRAMEWORK_DLL ezCapsuleGizmo : public ezGizmo
{
  EZ_ADD_DYNAMIC_REFLECTION(ezCapsuleGizmo, ezGizmo);

public:
  ezCapsuleGizmo();

  void SetLength(float fRadius);
  void SetRadius(float fLength);

  float GetLength() const { return m_fLength; }
  float GetRadius() const { return m_fRadius; }

protected:
  virtual void DoFocusLost(bool bCancel) override;

  virtual ezEditorInput DoMousePressEvent(QMouseEvent* e) override;
  virtual ezEditorInput DoMouseReleaseEvent(QMouseEvent* e) override;
  virtual ezEditorInput DoMouseMoveEvent(QMouseEvent* e) override;

  virtual void OnSetOwner(ezQtEngineDocumentWindow* pOwnerWindow, ezQtEngineViewWidget* pOwnerView) override;
  virtual void OnVisibleChanged(bool bVisible) override;
  virtual void OnTransformationChanged(const ezTransform& transform) override;


private:
  ezTime m_LastInteraction;

  ezVec2I32 m_vLastMousePos;

  ezEngineGizmoHandle m_hLengthTop;
  ezEngineGizmoHandle m_hLengthBottom;
  ezEngineGizmoHandle m_hRadius;

  enum class ManipulateMode
  {
    None,
    Length,
    Radius,
  };

  ManipulateMode m_ManipulateMode;

  float m_fRadius;
  float m_fLength;
};
