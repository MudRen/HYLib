// /d/gaoli/shanghang
// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ʤ��������--����¡��������еĻ���Զ����Ҷ����
�������ⶼ�����ķֵ꣬��˵������ϰ�ϲ���ղأ���Ʒ���������
����ϡ��Źֵ������챦��ֻ��˭Ҳû������
LONG
	);
set("exits", ([
               "north":__DIR__"baihu-1", 
	]));
set("objects", ([
		"/d/gaoli/npc/cui" : 1,
	]));

       setup();
	replace_program(ROOM);
}	
