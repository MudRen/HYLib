//  beihubian.c 
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������԰֮�Σ���벿���ڻ������У������������������ͱڣ�ֻ��
����������ɽ�±Ƚ���б���������������޷����ϣ�����������һ�ԴԵĲ�
����ҡ�����ˡ���ˮ�峺���������⡣
LONG
        );
        set("resource/water", 1);
        set("outdoors", "����");
        set("exits", ([
                "northeast" : __DIR__"donghubian",
		"southeast" : __DIR__"nanhubian",
                "north" : __DIR__"shulin4",
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
            message("vision", me->name()+"ſ�ں�����������һЩˮ�ȡ�\n"
            , environment(me), ({me}) );
            write("�����һ�ڴ�ɽ���ٲ����������ĺ�ˮ�������쳣��\n");
        }
        else write("����ô�����ˮ���㲻��������?\n");
        return 1;
}
