// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "�鷿");
	set("long", @LONG
�������������ڵ��鷿����������һ��С���ھ�Ȼ����˶�ĵ��Ҿ��䡣
�������ܶ��Ǵ���ܣ�����������飬�鷿�м��������Ӻͼ������ӣ�������
����ʹ�á�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "east" : __DIR__"yuxuguan",
        ]));
       
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
