//Npc �ȹ���ʮ��
//diabio(����)2003.3.1
#include <ansi.h>
inherit NPC;
int ask_tianxiang();
inherit F_MASTER;
void create()
{
        set_name("�ȹ���ʮ��", ({ "biguqing shilang", "shilang" }));
        set("long", "������糴彣�ĵ�ʦ���� \n");
        set("title", HIR"����������"HIY"����������"NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude","peaceful");
        set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("per", 50);
        set("per",23);
        set("tianyu_1",1);
        set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        create_family("����������", 5, "����");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
              set("inquiry", ([
           "����������":     "��ս��ʱ����ʼ����������������书��",
           "��������": (:ask_tianxiang:),
           "糴彣��":   "�������ǲ�Тͽ����"]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/wushidao")->wield();
}

void attempt_apprentice(object ob)
{
        if(ob->query("family/family_name")!="����������")
        {
                command("say �����ɵ��Ӳ���ѧ�ҹ���\n");
          return 0;
        }
        if(ob->query("combat_exp")<1000000)
        {
                 command("say ���ʵս�����������Ҳ��ܴ����㹦��\n");
            return 0;
        }
       	if ((int)ob->query_skill("huoxinliu-jianfa", 1) < 200) {
		command("say ��Ļ���������̫���ˣ���δ��������Ķ������ѧϰ�ҵ��书�ء�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѻ���������������������ɣ�");
		return;
        }
	if ((int)ob->query_skill("shayi-xinfa", 1) < 200) {
		command("say ���ɱ���ķ�̫��,���¿��Ʋ���ɱ�⡣"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ�ɱ���ķ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("aikido", 1) < 200) {
		command("say ��Ŀ��ֵ�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѿ��ֵ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("wuxing-dun", 1) < 200) {
		command("say ������ж�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ����ж�������������ɣ�");
		return;
	}
    if ((int)ob->query_skill("shayi", 1) < 200)
    {
        command("say ����֮������ɱ�⡣");
        command("say " + RANK_D->query_respect(ob) +
            "���ɱ��̫���ˣ�");
        return;
    }
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"��������������"HIR"����"NOR);
       ob->set("class", "yujianliu");
}
int ask_tianxiang()
{
    object ob;
    ob = this_player();

    tell_object(ob,"�ȹ���ʮ��˵�����콵��������߽�������Ҫѧ�������������ƴ���У�����������˾͸�������Ҥ��\n"); 
      command("go south");
      command("go west");
   command("sigh");
   return 1;
}
void kill_ob(object me)
{
if(!this_player())
{
::kill_ob(me);
return;
}
 if(this_player()->query("family/family_name")=="����������")
{
	command("say ���ҪС���ˣ��ó������������ɱ�ҡ�\n");
       this_player()->set("feitian/bigu",1);
	::kill_ob(me);
}
}
               
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (me && me->query("family/family_name")=="����������")
{ 
        message_vision("\n$N�������㲻���ѹ��������������������˶�����ˣ���Ҫѧ����߽������ž��������������㲻��̫�ѹ���\n", this_object());
me->set("feitian/tianxiang",1);
message_vision("\n������һ��������ᵽ�����������ľ��衣\n", this_object());
}
::die();
}