// tanan.c
// By River
inherit ROOM;
#include <ansi.h>

void create()
{
         set("short", HIY"ˮ̶����"NOR);
         set("long", @LONG
��վ��һƬɽ���е�һ��ˮ̶(tan�����ߡ���Ŀ�Ĺˣ�ֻ��������ݣ���
��һ������Ļ�԰��Ȼ����Ӱ�������Ĺ����ˣ�������ʮ�ְ������ݵ���һ��
���ѵ�С·�����˶���ʯ(shi)��ǰ����Զ��һ��é�ݡ�
LONG
        );
         set("item_desc", ([
            "tan":HIC"���Ŀ��̶����ȥ������ˮ̶����ˮ�ݻζ���������֪���İ���������ȥ��\n"NOR,
            "shi":"һ�����СС�Ķ���ʯ�����̲�ס���(jian)����������\n",
         ]));

         set("outdoors", "�����");

         set("exits", ([
               "north" : __DIR__"xiaolu",
         ]));   

         setup();

}

void init()
{
      add_action("do_tiao", "tiao");
      add_action("do_jian", "jian");
      add_action("do_xiao", "xiao");
}

int do_tiao(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "tan")
                return notify_fail("��Ҫ��������\n");
        message_vision(HIY"$N��ͨһ����ӿ��������ˮ̶��\n"NOR, me);
        me->set("water", me->max_water_capacity()+ 100);
        me->move(__DIR__"tanmian");
        tell_room(environment(me), me->name() + "�Ӱ�������������\n", ({ me }));
        return 1;
}

int do_jian(string arg)
{
        object me,ob;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "shi")
                return notify_fail("��Ҫ����ʲô��\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 100) 
                return notify_fail("��ĸ��ɹ����ˣ�\n");
        switch  (random(3)){
        case 0: ob = new(__DIR__"obj/shi1"); break;
        case 1: ob = new(__DIR__"obj/shi2"); break;
        case 2: ob = new(__DIR__"obj/shi3"); break;
        }
        ob->move(me);
        message_vision("$N���������ӵ��ϼ�����һ��"+ob->name()+"��\n",me);
        return 1;
}

int get_object(object ob)
{
       return userp(ob);
}

int do_xiao(string arg,object *obj)
{
        object me=this_player();
        mapping fam;
        object *inv = deep_inventory(me);        
        fam = me->query("family");
        if (arg) return 0;
        if( ! fam || fam["family_name"] != "��Ĺ��") return 0;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
          tell_object(me,HIR"�����͵͵���������ϰ׵񣬽������̫�࣬����һ����˩��ˤ���ڵء�\n"NOR);
          me->unconcious();
          return 1;
        }
        message_vision(HIW"\n$N���������е�ֻ���׵�˫��һ�񣬸߷����ƣ�������Ȧ���͵���ӿ��м�����¡�\n"+
                          "$N���ϰ׵���ǰ׵�����������������������ɽ�¡�\n\n"NOR,me);
        me->move(__DIR__"duanchang");
        tell_room(environment(me), me->name() + "�Ӱ׵����������������׵�˫��һ�񣬸߷����ơ�\n", ({ me }));
        return 1;
}
