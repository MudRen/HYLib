// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "а�¹㳡��ͥ");
	set("long", @LONG
������һ���ܿ����Ĺ㳡��������ʯ���档��Χ�ۼ��Ž����ϲ���аħ�����
�ܶ�а���������ﶼϲ���������Ϊ����ͨ������ɵıؽ�֮·��������ʿ
����������Զ֮�˴��������п�����(sign)��
LONG );
        
        set("type", "xie");
        set("no_npc",1);
	set("owner", "public");
	set("item_desc", ([
		"sign" : "�����ɵ������˿����ڴ˴�����(buildroom)һ�����Ϊ���á�\n",
	]));

	set("exits", ([
		"eastdown" : __DIR__"guangchang1",
			"westup" : __DIR__"guangchang13",
				]));
	
	setup();
}

void init()
{
        add_action("do_quit","buildrest");
        add_action("do_quit","buildeat");
        add_action("do_quit","buildweapon"); 
        add_action("do_quit","buildjob2");
        add_action("do_quit","buildjob");
        add_action("do_quit","buildfight");
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"������ֻ��buildroom��\n");
        return 1;
}
