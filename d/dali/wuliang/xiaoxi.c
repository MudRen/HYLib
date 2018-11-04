// xiaoxi.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "ɽ��СϪ");
        set("long", @LONG
��ɽ·���Ա��˳���һ��СϪ����Χ�������ˣ�ֻ����С����ˮ��������
�졣һЩ�ڿʵ�������Ϫ�ߺ�ˮ��Զ��������һЩ������ģ���Ķ���Ҳ��Ϫ��
���֡�������һ����ɽ��·�������涼�Ǿ����Ͱ��ݹ�ľ����������һ���Ữ
�����壬��ϡ��һ��С·ͨ�����
LONG
        );
        set("resource/water", 1);

        set("exits", ([
             "north" : __DIR__"shanlu8",                
	     "southwest" : "/d/dali/jianchuan",
             "southup" : __DIR__"shanlu5",
        ]));
set("no_npc",1);
        set("outdoors", "����");
        set("objects", ([
//            __DIR__"obj/yeguo" : 2,
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
            message("vision", me->name()+"ſ��Ϫ����������һЩˮ�ȡ�\n"
            , environment(me), ({me}) );
            write("�����һ�ڴ�ɽ������������Ϫˮ������������ˡ�\n");
        }
        else write("����ô�����ˮ���㲻��������?\n");

        return 1;
}

int valid_leave(object me, string dir)
{
        if(dir=="north" ){
        if(me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("�㲻�¾����Ͱ��ݹ�ľ������ƥ��\n");
        }
        return ::valid_leave(me, dir);
}
