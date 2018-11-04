// ying-kuang.c ����
// ����lywin 2000/8/27

#include <ansi.h>
inherit ITEM;  

string *kuang1=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang"});
string *kuang2=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang"});
string *kuang3=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang"});
string *kuang4=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang","/quest/skills2/wakuang/kuang/xuantie-kuang"});
string *kuang5=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang","/quest/skills2/wakuang/kuang/xuantie-kuang","/quest/skills2/wakuang/kuang/hantie-kuang1"});
string *kuang6=({"/quest/skills2/wakuang/kuang/tong-kuang","/quest/skills2/wakuang/kuang/tie-kuang","/quest/skills2/wakuang/kuang/ying-kuang","/quest/skills2/wakuang/kuang/jing-kuang","/quest/skills2/wakuang/kuang/xuantie-kuang","/quest/skills2/wakuang/kuang/hantie-kuang1","/quest/skills2/wakuang/kuang/hantie-kuang2"});

void init()
{
	add_action("do_wakuang", "wakuang");
}


void create() 
{
        set_name("����",({"kuang mai", "mai"}));
        set_weight(500000000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_put",1);
		set("no_get",1);
                set("long", "����һ���ܺõĿ�����������ã�wakuang�����������������Ρ�\n");
             }
        setup();
}

int do_wakuang()
{
        object me=this_player();

        if( me->is_busy() ) return notify_fail("�����ں�æ�������ڣ�\n");
        if ((me->query("combat_exp") < 100000))
        {  
          tell_object(me,"��ľ��鲻�㣡\n");
          return 1;
        }
        if ((me->query("jing") < 30))
        {  
          tell_object(me,"��ľ������ܼ��У��������ڿ�ʯ��\n");
          return 1;
        }
        else
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"�������״̬̫������ڿ�ʯ��\n");
          return 1;
        }
        else
        if ((int)me->query_condition("skill2_busy"))  
            {
         tell_object(me,"��ողŸɹ���,Ҫ��Ϣһ���ˣ�\n");
                      return 1;
            }

        message_vision(HIC"$N�Ӷ����俪ʼ�ڵ�������������\n"NOR,me);
        me->add("jing",-20);
        me->add("qi",-30);
        if (me->query("combat_exp")<1000000)
        {
        me->add("combat_exp",20+random(30));
        me->add("potential",20+random(20));
        }
        else 
        {
        me->add("combat_exp",6+random(19));
        me->add("potential",6+random(15));
        }
        me->apply_condition("skill2_busy",1+random(3));
        me->start_busy(6);   
       	call_out("wakuang",5,me);
       	me->stop_busy();
       	return 1;
}

int wakuang(object me)
{
      object ob;
      object ob1;        

      if (random(7)<1)
      {
          message_vision(CYN"һ���ھ�֮��$NʲôҲû�ڵ���\n"NOR,me);
//          this_player()->add("work/wakuang",1);
          return 1;
      }
      else
      if ((int)me->query("work/wakuang") > 600 )
        {
           message_vision(HIR"$N�������ڿ�����������ȥ����һ������ҳ�һ��ÿ�ʯ��\n"NOR,me); 
           me->add("work/wakuang",1);
           ob=new(kuang6[random(7)]);
           ob->move(me);
          destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 500 )
        {
           message_vision(HIY"$N�������ڿ�����������ȥ����һ������ҳ�һ��ÿ�ʯ��\n"NOR,me); 
           me->add("work/wakuang",1);
           ob=new(kuang5[random(6)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 400 )
        {
           message_vision(HIY"$N�������ڿ�����������ȥ����һ������ҳ�һ��ÿ�ʯ��\n"NOR,me); 
           me->add("work/wakuang",1);
           ob=new(kuang4[random(5)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }       
       else
      if ((int)me->query("work/wakuang") > 300 )
        {
           message_vision(HIY"$N�ڿ����з�����ȥ���ҳ�һ��ÿ�ʯ��\n"NOR,me); 
           me->add("work/wakuang",1);
           ob=new(kuang3[random(4)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 200 )
        {
           message_vision(HIY"$N�ڿ�����������ȥ���þò��ҳ�һ���ʯ��\n"NOR,me); 
           me->add("work/wakuang",1);
           ob=new(kuang2[random(3)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/wakuang") > 100 )
        {
           message_vision(HIY"$N�ڿ�����������ȥ���ò������ҳ�һ���ʯ��\n"NOR,me); 
           me->add("work/wakuang",1);
           ob=new(kuang1[random(2)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
      else
      { 
        message_vision(HIG"$N���˰��죬���ڷ�������һ��ʯͷ�ǿ�ʯ��\n"NOR,me); 
        me->add("work/wakuang",1);
        ob1 = new( __DIR__ "tong-kuang");
        ob1->move(me);
        destruct(this_object());
      }
      return 1;
}
