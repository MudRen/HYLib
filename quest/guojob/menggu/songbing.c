#include <ansi.h>
inherit NPC;
int heal_other();
void create()
{
    set_name("�ξ��˱�", ({ "shang bing", "bing" }));
    set("gender", "����" );//�Ա��������Ӧ
        set("long",
"һ���մ�ǰ�����������ξ����˱������������˵Ĳ��ᡣ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIC"���ιٱ�"NOR);
  set("qi",300);
  set("jing",300);
  set("max_qi",400+random(590));
  set("max_jing",400+random(590));
        set("per", 25);
        set("age", 22);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 200000+random(300000));
        set("chat_chance", 20);
        set("chat_msg", ({
                "�ξ��˱�˵������ѽѽ�����۰�����\n",
                "�ξ��˱�˵�������ȫ��������ʿ�����ܲ�ʧ����!\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 100+random(150));
        set_skill("blade", 100+random(150));
        set_skill("parry", 100+random(150));
        set_skill("dodge", 100+random(150));
	set("inquiry", ([
		"����" : "лл������Ը���ұ(jiuzhi)��!\n",
	]) );	
        
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();
  carry_object("/clone/misc/cloth")->wear();
}
void init( )
{
	object ob;
	add_action("heal_other","jiuzhi");
        call_out("hunting",180);
}

void hunting()
{
object ob=this_object();
write(HIR"�ξ��˱�����������Ϊ��ұ�ƣ���Ѫ����!\n"NOR);
destruct(ob);
}



int heal_other()

{

        object me=this_player(); 

        object ob=this_object(); 

        if (me->query("gender")=="����")
   return notify_fail(HIC"�����²��ʺϴ������������㻹��ȥ���аɡ�\n"NOR);

        if ( (int)me->query("jing")<20)

           return notify_fail("��̫���ˣ�ЪϢ�°ɡ�\n");

        if (me->query_temp("guo/sanbing")>9)

           return notify_fail("�����Ѿ�ұ�ƺ��ˣ�\n");

   

  message_vision(HIB"$N�������������ڹ�������������$n���ģ������ؽ���������$n����....��\n"NOR,me,ob);

      me->add("jing",-me->query("eff_jing")/10);

      me->add_temp("guo/sanbing",1);

  if ( (int)me->query_temp("guo/sanbing")==8)

 {

  message_vision(CYN"$N���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,ob);


      me->delete_temp("guo/sanbing");
   if((int)me->query("combat_exp") < 1000000)   {
  message("vision", me->name() + HIG"���ڳɹ��ľ�ұ���α��˱�,������200�����100Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",200);
        me->add("potential",100);
        me->add("score",30);
        destruct(ob);
        }
        message("vision", me->name() + HIG"�ɹ��ľ�ұ���α��˱���\n"NOR, me);
        me->add("score",2);
        me->add("shen",10);
        destruct(ob);

      
 }

      return 1;

} 

