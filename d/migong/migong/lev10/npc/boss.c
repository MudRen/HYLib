// migong lev10  du

#include <ansi.h>

inherit NPC;


void create()
{
  
      set_name(MAG"ä����"NOR,({ "mang popo" , "popo" }));
 
       set("gender", "Ů��" );
 set("long",
"�ٶ������ʦ��,�书���ߣ��򱻰ٶ�������㶾Ϲ��
˫�ۣ����Զ���ڴΡ�\n");
        	  set("force_factor",100+random(200));
  set("max_qi",9000+random(4200));
  set("max_jing",9000+random(4200));
  set("max_sen",9000+random(4200));
  set("max_neili",9000+random(4000));
  set("max_mana",9000+random(4000));
  set("eff_neili",12500+random(4000));
  set("neili",19000+random(4000));
set("attitude", "aggressive");
        set("per", 1);
        set("age", 52);
set("no_get",1);
       set("jiali" , 200);
        set("shen", -10000);
               set("combat_exp", 8000000+random(2000000));
                 set_skill("claw", 400+random(60));

set_skill("unarmed", 400+random(60));

        set_skill("force", 300);
        set_skill("wudu-shengong", 300);
        set_skill("dodge", 290);
        set_skill("wudu-yanluobu", 250);
        set_skill("unarmed", 260);
        set_skill("qianzhu-wandushou", 260);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 280);
        set_skill("poison", 260);
        set_skill("literate", 280); 
        set_skill("finger",260);
        set_skill("shedu-qiqiao",260);
         set("chat_chance_combat", 90);
         set("chat_msg_combat", ({
                (: perform_action, "finger.sandu" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "finger.sandu" :),
                (: perform_action, "dodge.snake" :),
        }) );


        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");

        create_family("�嶾��", 11, "����");
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 550);
 
          set_temp("apply/armor", 350);
        set_temp("apply/damage", 350);


   set("inquiry", ([       
"�ٶ����" : "������ʦ�ܣ�������Ĺ��ϵĶ������ҵ��۾���������Ϲ�ġ�",
"�ٶ�����" : "�ٶ�����Ҳ����ʦ�ܣ���Ҳ���Ǹ��ö���������ʦ���Ǳ�Ϊ�顣",
"�۾�" : "�ҵ��۾��Ǳ��ϳ��ݶ�Ϲ�ģ�ֻ�����ĺ������Ρ�",
"���ĺ���" : "��˵���ĺ��ľ�ֻ�����������У�����������þ���û�ҵ���"
]) );  

        setup();

        carry_object("d/wudujiao/npc/obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("d/wudujiao/npc/obj/wuxing");    
   carry_object("/d/migong/obj/zhang")->wield();
	
    

}

int accept_object(object who, object ob)
{
	   if ((string)ob->query("id")=="qixin haitang") {
            say(MAG"ä����"NOR"�����Ľе����������첻����,�������ܱ����ˣ���
˵��ʹҴ�ææ�뿪�ˡ�
\n");
           move("/d/migong/lev8/dong101");
            }
		return 1;
}

int hit_ob(object me, object ob, int damage)
{
if (ob)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ����еĵط�һ��������\n" NOR );
}
}

void die()
{
        object ob, me, corpse,obj;
   int exp,pot,score,i;     
int maxpot;
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;   
             me->add("score",1000);
        me->add("shen",1000);
        
        message_vision(WHT"$N��������!!��\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev10"))
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
if (!me->query("migong/lev10"))
{
me->set("migong/lev10",1);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "������Թ���ʮ��!"NOR"��\n", users());
exp = 380000+random(25000);
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
        if((int)me->query("combat_exp") < 5000000)   {
        message("vision", me->name() + "Ϊ��������,������400�����200Ǳ�ܡ�\n", me);
        me->add("combat_exp",400);
        me->add("potential",200);
        destruct(ob);
        }
        destruct(ob);
        return;
}
