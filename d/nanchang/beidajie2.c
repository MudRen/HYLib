
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�������ϲ��ı���֡��ϱ߾����ϲ��������ˡ����������������
�����ֵ������������οʹ���������߹�������̸�������������ľ�ɫ��
·���кܶ���ˣ�����ˣ������нкõ����������ﴫ����
LONG);

  set("exits", ([ 

  "south":__DIR__"center",
 "east":__DIR__"yanju",
  "north":__DIR__"beidajie1",
         ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

