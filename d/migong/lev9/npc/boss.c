// migong lev9 boss

#include <ansi.h>

inherit NPC;


void create()
{
  
        set_name(WHT"������"NOR, ({ "jiguan ren" , "ren" }));
 
set("title", HIG"�ɶ��칦"NOR);
   set("gender", "����" );
 set("long",
"һ�߽�ʵ���־��µĻ����ˡ�\n");
         set("force_factor",100+random(200));
  set("max_qi",999999+random(99999));
  set("max_jing",99999+random(99999));
  set("max_sen",99999+random(99999));
  set("max_neili",99999+random(99999));
  set("max_mana",99999+random(99999));
  set("eff_neili",9999+random(9999));
  set("neili",9999+random(9999));
        set("per", 1);
        set("age", 32);
set("no_get",1);
       set("str" , 100);
       set("jiali" , 100);
        set("shen", -10000);
        
        set("combat_exp", 4500000+random(1200000));
                 set_skill("unarmed", 330+random(50));

 set_skill("taixuan-gong", 530+random(50));

set_skill("force", 530+random(50));
set_skill("parry", 530+random(50));

set_skill("dodge", 530+random(50));

  
        map_skill("unarmed", "taixuan-gong");
  
      map_skill("parry", "taixuan-gong");

 map_skill("force", "taixuan-gong");

 map_skill("dodge", "taixuan-gong");
 
prepare_skill("unarmed", "taixuan-gong");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
              	
         (: exert_function, "recover" :),
	    }) );
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 400);
 
          set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
  
  	

}
void unconcious()
{
    die();
}

void die()
{
        object ob, me, corpse,obj;
   int maxpot;
   int exp,pot,score,i;     
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;   
             me->add("score",1000);
        me->add("shen",1000);
        
        message_vision(WHT"$N��������!!��\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev9"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
{
obj=new("/d/migong/obj/npct"); 
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц���������ʶ��һ������������! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}
else 
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		obj->test_robot(me);
}
}

if (!me->query("migong/lev9"))
{
me->set("migong/lev9",1);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "������Թ��ھŲ�!"NOR"��\n", users());
exp = 370000+random(25000);
pot = exp/2;
score = random(300)+550;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);
i=random(8);
	if (i==7) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i==6) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
        }
	}
	else if (i==5) {
        if ( me->query("dex")< 60)
        {
	me->add("dex",1);tell_object(me,HIM"�Լ�һ������\n"NOR);
        }
	}
	else if (i==4) {
        if ( me->query("str")< 60)
        {
	me->add("str",1);tell_object(me,HIM"�Լ�һ��������\n"NOR);
        }
	}
	else if (i==3) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i==2) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
        }
	}
	else if (i==1) {
        if ( me->query("con")< 60)
        {
	me->add("con",1);tell_object(me,HIM"�Լ�һ����ǡ�\n"NOR);
        }
	}
	else if (i==0) {
        if ( me->query("int")< 60)
        {
	me->add("int",1);tell_object(me,HIM"�Լ�һ�����ԡ�\n"NOR);
        }
	}
	else if (me->query("per")< 100) {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
	}
}
        if((int)me->query("combat_exp") < 6000000)   {
        message("vision", me->name() + "Ϊ��������,������400�����200Ǳ�ܡ�\n", me);
        me->add("combat_exp",400);
        me->add("potential",200);
        destruct(ob);
        }
        destruct(ob);
        return;
}
