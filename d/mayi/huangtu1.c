// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
���߳������ص����ţ�������һ���޼ʵ�ƽԭ����ɫ��������ɫ��
�ݣ��������죬����£���ԭ����һȺȺ������ż��������һȺҰ��
�ܹ���
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "east" : __DIR__"ximenwai",
                "westup" : __DIR__"changcheng1",
	]));
       setup();
	replace_program(ROOM);
}
