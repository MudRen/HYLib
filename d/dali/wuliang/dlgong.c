// Room: dlgong.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��������");
	set("long", @LONG
��������ɽ�������������������������������ܣ�ʮ������������ȫ��ǽ
�ǻ�ɢ���ż���������ʯ����һЩ������е���ÿ���ڴ������� 
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"jhg",
        ]));

	setup();
        replace_program(ROOM);
}
