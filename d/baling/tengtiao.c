
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",YEL"ɽ��Ʈ��������"NOR);
  set ("long", @LONG
��˫�ֽ�����ץ��һ����������������������һ��͸���������ɵ� 
���������Ӷ԰���ɽ�¡��磬�ڶ��ߺ�Х���ļ��Ļƺ�ˮ�����汼�ڣ� 
�㲻�ɱ�����˫�ۣ��������Ŷ���ɽ�µ��˹�ȥ�����л���˻���ߵĺ� 
�ţ���������������������......���� 
LONG);

 set("outdoors","tengtiao");
  set("valid_startroom", 1);
  setup();
 
}

