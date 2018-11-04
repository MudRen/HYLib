// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// ����Ⱥ
// ��npc�ϵ�xunshan���ò�����
// ����lywin����2000/6/11

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_xunshan();
string ask_me();
string ask_feng();

void create()
{
        set_name("����Ⱥ", ({ "yue buqun", "yue" }) );
        set("title", "��ɽ������");
        set("nickname", "���ӽ�");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "����Ⱥ����ִ�ƻ�ɽ�ɣ��˵���������һ��һ�ĸ��֡�\n");
        set("attitude", "peaceful");
        set("str", 56);
        set("con", 50);
        set("dex", 50);
        set("int", 58);

        set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", -200000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
	    "����" : (: ask_me :),
	    "����" : (: ask_me :),
	    "������" : "�����ҷ��ˡ�\n",
	    "�����" : "������Ů����\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",          
	    "˼����" : "���Ǳ��ɵ�������˼��֮����\n", 
	    "������" : (: ask_feng :),
            "Ѳɽ": (: do_xunshan :),
            "job" : (: do_xunshan :),
        ]) );

        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
}

string ask_me()
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( !myfam || myfam["family_name"] != "��ɽ��" )
		return "���Ǻ���ԨԴ���������¸��\n";

	say("����Ⱥָ�������Ҷ�����ĳ���˵��������ɽ��������Ϊ�������ڡ���\n");
	say("�����ڷ���Ϊ�����Խ�Ϊ���������˽����޼᲻�ݡ�������������ʩ�ؽ�\n");
	say("���������ڸ��ּ���������ˮ���ݣ�ͬ�Ųٸ꣡��ɽ���ʽ΢���㼴����\n");
	say("�ţ������ܽ����԰�������ɽ���ǵõ����Ҷ���д���ǡ���������������\n");
	say("�������佣·�ݺᣬ�仯�޷�������Ȼ�������ڡ���ϼ�񹦡�֮�£���ʮ��\n");
	say("���������֣�ʵ�첻ʤ��Ҳ����\n");
me->set_temp("mb",1);
	return "�мǣ��мǣ�\n";
}

string ask_feng()
{
	say("����Ⱥ����ɫͻȻ��ú��ѿ�������üͷ��\n");
	return "���Ǳ��ŵ�һ��ǰ����һ�򲻹��ʱ���������Ҳ������������䡣\n";
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say �һ�ɽ���Խ���Ϊ�������ҿ�"+RANK_D->query_respect(ob)+"���ʺ���ѧ������");
        else {
                command("say �ã��ã��ã��ܺá�");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        add("apprentice_availavble", -1);
}
void reset()
{
        set_temp("xunshan",200);
        set("apprentice_available", 3);
}
int do_xunshan()
{
        object me = this_player();
object killer;int k,exp,pot;

        if ( me->query_temp("xunshan"))
        {
              if(me->query_temp("killhuashan")<3)
               {
                      message_vision("$N����$n˵����˵����ĵ��˲�û�б�����!!\n", this_object(), me);
                      return 1;
               }

              if(me->query_condition("huaxunshan")>0)
               {
                      message_vision("$N����$n˵����Ѳɽ��ʱ�仹û����!\n", this_object(), me);
                      return 1;
               }

              if(me->query_condition("guojob2_busy")>0)
               {
                      message_vision("$N����$n˵������Ϣһ������!\n", this_object(), me);
                      return 1;
               }

               if (!me->query_temp("xunshan/chaoyang"))
               {
                      message_vision("$N����$n˵���㳯����ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N����$n˵����������ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N����$n˵������̨��ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N����$n˵������ôûȥ�����£�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N����$n˵���㵽��˼����ȥ�ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N����$n˵���㵽��Ů����滪ɽС��ȥ�����ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               message_vision("$N����$n˵�����������ˡ������ȥ��Ϣȥ�ɡ�\n", this_object(), me);
               me->delete_temp("killhuashan");                      
               me->delete_temp("xunshan");                      
               if (me->query("combat_exp")<800000)
               {
               me->add("combat_exp", 80);
               me->add("potential", 50);
               }
exp= random(270) + 250;
pot= random(200) + 180;
               me->add("combat_exp",exp);
               me->add("potential",pot);
   tell_object(me, "�㱻������"+chinese_number(exp)+"�㾭��ֵ��\n"+chinese_number(pot)+"��Ǳ��\n");
               return 1;
        }
        else
        {
               if ( query_temp("xunshan") < 1)
               {
                      message_vision("$N����$n˵�������Ѿ�����Ѳɽȥ�ˡ������������ɡ�\n", this_object(), me);
                      return 1;
               }
      if( (int)me->query_skill("zixia-shengong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
               if( me->query("family/family_name") != "��ɽ��")
               {
                      message_vision("$N����$n���һ�������ɵ��Ӳ���Ѳɽ�����������ļ�ϸ���ݹ��ҽ��²����飡\n", this_object(), me);
                      this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add_temp("xunshan", -1);
                      message_vision("$N����$n˵�����ɵ�������Ѳɽ���㣬�ܺã��ܺã����ȥ�ɡ�\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
	              me->apply_condition("huaxunshan",8);
if (me->query("combat_exp") >800000)
{
        message_vision(HIR"��˵��ɽ�������������в�����ݵ������ˣ������ȥ̽��һ�£�\n"NOR, me);
killer=new(__DIR__"killer",1);
killer->set_temp("owner/id",me->query("id"));
killer->set("id",me->query("id")+"-mengmian");
killer->set_temp("owner/id",me->query("id"));
killer->set("id",me->query("id")+"-mengmian");
killer->set("name",HIB"������"NOR);
if ((int)me->query_skill("force",1) > 10)
{
k=(int)me->query_skill("force",1);
}
else k=10;
killer->set("int",me->query("int"));
killer->set("str",me->query("str"));
killer->set("con",me->query("con"));
killer->set("dex",me->query("dex"));


        killer->move("/d/huashan/hsforest"+(random(19)+1));
        killer->set("combat_exp",me->query("combat_exp"));
        killer->set("qi", me->query("max_qi"));
        killer->set("eff_qi", me->query("max_qi"));
        killer->set("max_qi", me->query("max_qi"));
        killer->set("jing", me->query("max_jing"));
        killer->set("eff_jing", me->query("max_jing"));
        killer->set("max_jing", me->query("max_jing"));
        killer->set("neili", me->query("max_neili"));
        killer->set("max_neili", me->query("max_neili"));
         killer->set_skill("tmzhang", k);
        killer->set_skill("staff", k);
         killer->set_skill("tmjian", k);
         killer->set_skill("tmdao", k);
         killer->set_skill("pmshenfa", k);
          killer->set_skill("strike",k);
         killer->set_skill("blade", k);
          killer->set_skill("sword", k);
          killer->set_skill("parry", k);
        killer->set_skill("literate",k);
          killer->set_skill("dodge", k);
          killer->set_skill("unarmed", k);
          killer->set_skill("whip", k);
          killer->set_skill("force", k);
         killer->set_skill("tmzhang", k);
         killer->set_skill("tmdafa", k);
}
                      return 1;
               }
        }
}
