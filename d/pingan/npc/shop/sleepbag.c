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
set("no_put",1);
set("no_get",1);
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
        object where,ob;
        mapping fam;
        
        me = this_player();
        ob = this_object();
        where = environment(me);
        if( where->query("no_fight") ){
        return notify_fail("���ﲻ��ʹ��˯����\n");
        }

        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в���˯����\n");

        if (!wizardp(me) && me->query("age") > 18)  
                return notify_fail("���ϴ�С�˻���˯�����߲��ߣ�\n");
       
        if( !objectp(ob = present("sleep bag", me)) )
                return notify_fail("��û��˯����\n");

        if( environment(ob)!= me )
                return notify_fail("��û��˯����\n");

        if (where->query("sleep_room")==1)
        {
                write("��������һ�ɣ���ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
			me->set_leader(0);
                me->set_temp("block_msg/all",1);
                me->start_busy(2);
                message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
            rnd = random((60 - me->query_con()) / 3);
        }
        if (me->query("age") > 18) { 
                return notify_fail("���ϴ�С�˻���˯�����߲��ߣ�\n");
       }
        if( where->query("no_fight") ){
        return notify_fail("���ﲻ��ʹ��˯����\n");
        }
                write("��չ��һ��˯�����˽�ȥ����ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
			me->set_leader(0);
                me->start_busy(2);
                me->set_temp("block_msg/all",1);
                message_vision("$Nչ��һ��˯�����˽�ȥ����һ�����������������������\n",me);
            rnd = 10 + random((100 - me->query_con()) / 3);
//        where->set("no_fight", 1);
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
if (!me) return;
if (!where) return;
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
  
        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
			me->set_leader(0);
        me->set_temp("block_msg/all", 0);
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");


        if (!where->query("sleep_room") && !where->query("hotel"))
//                where->delete("no_fight");
     
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");
        me->set_temp("sleepbag", 0);      

}


