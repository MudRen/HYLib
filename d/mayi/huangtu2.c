// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
�������ڻ�����ԭ�ϣ�������һ���޼ʵ�ƽԭ����ɫ��������ɫ��
�ݣ��������죬����£���ԭ����һȺȺ������ż��������һȺҰ��
�ܹ���
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "eastup" : __DIR__"changcheng2",
                "southwest" : __DIR__"dukou1",
	]));
       setup();
	replace_program(ROOM);
}
