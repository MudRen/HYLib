
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ƕ���֡������ǾŽ�������㳡�����Ǳߴ��������ֵ�������
��ʱ�м�λ[����¥]�Ĺ����߹������������Ž��ϵ����ӡ���������Ȼ��
������㳡��ô�࣬��������Ҳ��Ħ����࣬ӵ�������ˡ�
LONG);

  set("exits", ([ 

 "east":__DIR__"dongdajie2",
  "west":__DIR__"center",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

