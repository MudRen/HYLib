// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ɭ��");
	set("long", @LONG
�����������ǲ����ľ���м�ȴ��һ����Ȫ���㲻�ɵĴ�ϲ������������
��Խ���Ľ��ܣ��������롣� 
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "east" : __DIR__"shanlin-4",
	    "north" : __DIR__"shanlin-6",
	]));

	setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"ſ��Ȫ����������һЩˮ�ȡ�\n"
            , environment(me), ({me}) );
            write("�����һ��������Ȫˮ������������ˡ�\n");
        }
        else write("����ô�����ˮ���㲻��������?\n");
        return 1;
}
