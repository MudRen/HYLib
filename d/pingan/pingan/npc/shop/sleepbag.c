// sleepbag.c

void wakeup(object,object);

inherit ITEM;

void create()
{
    set_name("˯��", ({ "sleep bag","bag"}) );
        set_weight(1500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "ֻ");
          set("long", "һ��������ʱ˯��(sleephere)��˯����\n");
          set("value", 30000);
        }
}

int is_container()      {return 1;}

int init()
{
    add_action("do_sleephere", "sleephere");
}

int do_sleephere(object me, string arg)
{
        int rnd;
        object where;
        mapping fam;
        me = this_player();

        where = environment(me);
        
        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в���˯����\n");

        if (where->query("sleep_room")==1)
        {
                write("��������һ�ɣ���ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                me->set_temp("block_msg/all",1);
                message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
            rnd = random((60 - me->query_con()) / 3);
        }
//        if ( (where->query("no_fight")==1)||(where->query("no_sleep")==1)||(where->query("no_steal")==1))
//       {
//                return notify_fail("���ﲻ��ʹ��˯����\n");
//        }
        if (me->query("age") > 18) { 
                return notify_fail("���ϴ�С�˻���˯�����߲��ߣ�\n");
       }
        else { 
                write("��չ��һ��˯�����˽�ȥ����ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                me->set_temp("block_msg/all",1);
                message_vision("$Nչ��һ��˯�����˽�ȥ����һ�����������������������\n",me);
            rnd = 10 + random((100 - me->query_con()) / 3);
        }
        where->set("no_fight", 1);
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        me->set_temp("sleepbag", 1);
        if (!(where->query("hotel"))) 
                me->set_temp("sleeped",1);
        else
                me->delete_temp("rent_paid");

        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        
        return 1;
}

void wakeup(object me,object where)
{
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
  
        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
        me->set_temp("block_msg/all", 0);
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");

        if (!where->query("sleep_room") && !where->query("hotel"))
                where->delete("no_fight");
     
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");
        me->set_temp("sleepbag", 0);      

}


