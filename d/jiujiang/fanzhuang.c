
inherit ROOM;


void create ()
{
  set ("short","�Ž���ׯ");
  set ("long", @LONG
�����ǾŽ������ķ�ׯ����ǰ����һ����������ÿ��ҹ��ͻ��
���������ż����ֶ����������������ǰ�ġ��Ž���ׯ��������������
���⡣ÿ�춼�кܶ���������Է�����С��æ����ͣ��
LONG);

  set("exits", ([ 

  "north":__DIR__"xidajie1",
        ]));
 set("objects",([
	 __DIR__"npc/xiaoer1":1,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

