// /d/taiyuan/nroad3.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
������һ����������Ĵ�ٵ��ϡ��˴�����Ⱥϡ�١�������Ǵ��
ԭ�ˡ�
LONG
        );
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "southup":__DIR__"changcheng9",
                "north":__DIR__"nanmen",

	]));
       setup();
	replace_program(ROOM);
}
