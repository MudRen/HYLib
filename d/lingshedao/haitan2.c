//Room:/d/lingshedao/haitan2.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��̲");
        set("long", @LONG
����һƬƽ̹�ĺ�̲,��ǰ��ε���Ĵ�.��̲����
ͣ��һֻС��(boat),Զ��ͣ��һ�Ҿ޴��ս��.
LONG);
        set("exits", ([
                "southwest"    : __DIR__"lsroad5",
       ]));
        set("item_desc",([
               "boat" : "����enter����С��.\n",
        ]) );       
               
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter()
{
        object ob=this_player();
        message_vision("$N�߽�С��,����ʻ��ãã��....\n",ob);
        ob->move("/d/taohua/dahai");
        tell_object(ob,BLU"���ں��Ϻ����˺ܾúܾ�.......\n" NOR );
        call_out("go_quanzhou",10,ob);
        return 1;
}

void go_quanzhou(object ob)
{
       tell_object(ob,"�����ڿ�����һ��������.�㼱æ�����˴�.\n");
       ob->move("/d/quanzhou/haigang");
}
