inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ˣ�����λ�ڹ���֮���ϣ����֮�����������ҳ�
����֮�ƣ��Թ�Ϊ���ұ���֮�أ��������´��ң�Ⱥ�۲�������Ҳ��
�����֣�������˭�����ﶼ�����ر�������Ϊ�����Ǿ����صأ����Զ�
�����������̲��ʮ���ϸ�	
LONG );

	set("exits", ([
               "east"      : __DIR__"heyang",
               "north"      : __DIR__"tulu4",

	]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



