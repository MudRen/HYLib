// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "�ݵ�");
    set("long",@LONG
����һƬ�տ��Ĳݵأ����ܳ������Ӳݣ��ƺ������Ѿ��ܾ�û��
�������ˣ�������Ұ�ĵط���������в��ɵ�����һ˿���⡣����
���߾���һ������׵ľ����ˡ�
LONG
);
        set("outdoors","changan");
    set("exits", ([
        "west" :__DIR__"boshulin10",
        "east" :__DIR__"jueya",
]));
    set("item_desc", ([
"�ݵ�" : "����Ƭ�ݵص��м䣬���ƺ��е�һЩ������\n",
]));
    setup();
}

void init()
{
    if (interactive(this_player()))
    add_action("do_kill","sha");
}

void check(object me,object ob)
{
    if (!me || !ob)
        return;
    if (!present(me,this_object())
        || !present(ob,this_object()))
        return;
    if (me->query("max_neili")<600
        || ob->query("max_neili")<600)
        return;
    if (ob->query("max_neili") < me->query("max_neili")){
        message_vision(HIR"$n��$N����һ�����±ߵ�����ȥ��\n"NOR,me,ob);
      ob->move("/d/changan/qinhuang/gudi");
        ob->set_temp("killer",1);
        ob->unconcious();
    }else{
        message_vision(HIR"$N��$n����һ�����±ߵ�����ȥ��\n"NOR,me,ob);
      me->set_temp("killer",1);
      me->move("/d/changan/qinhuang/gudi");
        me->unconcious();
    }
}

int do_kill(string arg)
{
    object ob,me=this_player();
    
    if (!arg || arg=="")   return 0;
    if (ob=present(arg,this_object())){
message_vision( HIY "$N��$nһ���棬������ɱ��������\n" NOR ,me,ob);
        ob->kill_ob(me); me->fight_ob(ob);
        if (userp(ob))
            if ( ob->query("jiali") > 50
            && me->query("jiali") > 50){
                remove_call_out("check");
                call_out("check",random(20)+5,me,ob);
            }
    }
    return 0;
}

