// Room: sec2
// congw 980830 

inherit ROOM;
void create()
{
	set("short", "��Ĺ�ڲ�");
	set("long", @LONG
�������һ�߹ײģ���ž���Ĺ������д����˪�����Ĺײ��ˡ���ֵ��ǹײ��ѱ���
���Ա߷��Ź׸�(cover)��
LONG
	);

	set("exits", ([
		"out" : __DIR__"houyuan",
		"northup" : __DIR__"sec2",
		]));


	set("item_desc", ([
		"cover" : "��Ĩȥ����Ļҳ���ֻ��������д��Щ����ֵֹ����֣�����ʮ������ʮ�ߡ�һʮ�ˡ���ʮ������ʮһ�� \n",
	]));

        set("no_clean_up", 0);
       

        setup();
        replace_program(ROOM);
}

