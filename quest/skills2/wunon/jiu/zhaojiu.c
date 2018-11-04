// ying-kuang.c ����
// ����lywin 2000/8/27

#include <ansi.h>
inherit ITEM;  

string *kuang1=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3"});
string *kuang2=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4"});
string *kuang3=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5"});
string *kuang4=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5","quest/skills2/wunon/jiu/eat6"});
string *kuang5=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5","quest/skills2/wunon/jiu/eat6","quest/skills2/wunon/jiu/eat7"});
string *kuang6=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5","quest/skills2/wunon/jiu/eat6","quest/skills2/wunon/jiu/eat7","quest/skills2/wunon/jiu/eat8"});

void init()
{
	add_action("do_wakuang", "zhaojiu");
}


void create() 
{
        set_name("��Ƴ�",({"zhaojiuchang", "chang"}));
        set_weight(500000000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_put",1);
		set("no_get:",1);
                set("long", "����һ��ܺõ���Ƴ���������ã�zhaojiu�����������������Ρ�\n");
             }
        setup();
}

int do_wakuang()
{
        object me=this_player();

        if( me->is_busy() ) return notify_fail("�����ں�æ��������ƣ�\n");
        if ((me->query("jing") < 30))
        {  
          tell_object(me,"��ľ������ܼ��У���������ƣ�\n");
          return 1;
        }
        else
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"�������״̬̫�������ƣ�\n");
          return 1;
        }
        else
        if ((int)me->query_condition("skill2_busy"))  
            {
         tell_object(me,"��ողŸɹ���,Ҫ��Ϣһ���ˣ�\n");
                      return 1;
            }

        message_vision(HIC"$N������ƹ��߿�ʼ����Ƴ�����ơ�\n"NOR,me);
        me->add("jing",-40);
        me->add("qi",-50);
        if (me->query("combat_exp")<1000000)
        {
        me->add("combat_exp",20+random(30));
        me->add("potential",15+random(15));
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

      if (random(7)<2)
      {
          message_vision(CYN"һ���Ͷ�֮��$Nʲô��Ҳû�����\n"NOR,me);
//          this_player()->add("work/zhaojiu",1);
          return 1;
      }
      else
      if ((int)me->query("work/zhaojiu") > 600 )
        {
           message_vision(HIR"$N����������Ƴ�����һ�ᣬ��һ��������˺õ��ջ�\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang6[random(8)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 500 )
        {
           message_vision(HIY"$N����������Ƴ������һ�ᣬ��һ��������˺õ��ջ�\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang5[random(7)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 400 )
        {
           message_vision(HIY"$N����������Ƴ������һ�ᣬ��һ����������ջ�\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang4[random(6)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }       
       else
      if ((int)me->query("work/zhaojiu") > 300 )
        {
           message_vision(HIY"$N����Ƴ������һ�ᣬ�����ջ񡣡�\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang3[random(5)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 200 )
        {
           message_vision(HIY"$N����Ƴ������һ�ᣬ�ó�ʱ��������ջ�\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang2[random(4)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 100 )
        {
           message_vision(HIY"$N����Ƴ���������ȥ���ò����������ջ�\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang1[random(3)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
      else
      { 
        message_vision(HIG"$N���˰���ľƣ���������һ���ջ�\n"NOR,me); 
        me->add("work/zhaojiu",1);
        ob1 = new( __DIR__ "eat1");
        ob1->move(me);
        destruct(this_object());
      }
      return 1;
}
