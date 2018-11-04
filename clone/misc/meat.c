
//  meat.c
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("����", ({ "fried meat", "meat" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ŀ���\n");
                set("unit", "��");
                set("value", 3);
                set("food_remaining", 8);
                set("food_supply", 8);
                set("material", "bone");
                set("decayed",0);
        }
        setup();
}
void eat_decayed(object me)
{
   int waittime;
object obj=this_object();
if (!me) return;

this_object()->set("decayed",0);
this_object()->delete("decayed");
   waittime=10-me->query_con()/10;
   if (waittime<3) waittime=3;
   me->start_busy(waittime);
   me->add("jing",-me->query("jing")/10);
   me->add("qi",-me->query("qi")/10);
   me->add("eff_jing",-me->query("eff_jing")/10);
   me->add("eff_qi",-me->query("eff_qi")/10);

message_vision("$N��ʣ�µ�$n�Եøɸɾ�����\n", me, obj);
   message_vision("$N��Ȼ���ö����ﹾཹ��ֱ�죬���˿�ɾ��ط��Ͷ�������...\n�أ��ó���\n", me);
destruct(this_object());
   return;
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   int foo;
object obj=this_object();
object me=this_player();
//   foo=::do_eat(arg);
//   if (!foo) return foo;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
   obj->set("value", 0);
    obj->add("food_remaining", -1);
me->add("food", obj->query("food_supply"));            
    if( !obj->query("food_remaining") 
    && !obj->query("decayed")) {
	     obj->delete_temp("apply/long");
	     if((string)obj->query("finish_msg"))
	           message_vision(obj->query("finish_msg"), me, obj);
	     else message_vision("$N��ʣ�µ�$n�Եøɸɾ�����\n", me, obj);
		   destruct(obj);
	     } 
   if (query("decayed")<1)
       message_vision("$N����" + name() + "�ǳ��óԣ���������һ����\n", this_player());
   else
   {
     message_vision("$N����" + name() + "ζ���ֵֹġ�\n", this_player());
     call_out("eat_decayed",6,this_player());
   }
  return 1;
}
