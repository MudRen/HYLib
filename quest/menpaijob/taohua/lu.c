// lu.c
#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
int ask_job();
int ask_fail();
void create()
{
        set_name( "½�˷�" ,({ "lu chengfeng", "lu" }));
        set("gender", "����");
        set("age", 52);
        set("long",
            "½�˷��ǻ�ҩʦ�ĵ��ĸ�ͽ�ܡ�\n"
            "�����޽���΢���׷�������Ŀ��࣬˫������\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 50);
        set("int", 58);
        set("con", 50);
        set("dex", 50);
        set("chat_chance", 1);
        set("max_qi",35000);
        set("max_jing",35000);
        set("neili", 65000);
        set("max_neili", 65000);
        set("jiali", 100);
        set("shen_type",1);

        set("combat_exp", 3300000);
        set_skill("force", 220);             // �����ڹ�
        set_skill("bibo-shengong", 220);     // �̲���
        set_skill("unarmed", 220);           // ����ȭ��
        set_skill("xuanfeng-leg", 220);      // ����ɨҶ��
        set_skill("strike", 220);            // �����Ʒ�
        set_skill("luoying-zhang", 220);     // ��Ӣ����
        set_skill("dodge", 170);             // ��������
        set_skill("anying-fuxiang", 270);    // ��Ӱ����
        set_skill("parry", 190);             // �����м�
        set_skill("sword", 190);             // ��������
        set_skill("luoying-shenjian", 190);  // ��Ӣ��
        set_skill("literate",190);           // ����ʶ��

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");

        set_temp("jinbing", 30);
        create_family("�һ���", 2, "���� ����ׯ��");

        set("inquiry", ([
           "�һ���":   "��������һ������������Ǳ��ɵ��ӣ�Ҫ���һ���",
           "�һ���":   "���Ͼ����ˡ�",
           "��а":     "��ʦ�˳ƶ�а���Ǻǡ�",
           "����":     "ŷ���������ʦ���������ĸ��֣��˳��϶��",
           "�ϵ�":     "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
           "��ؤ":     "��ؤ���߹���ؤ��������������ݳ��⡣",
           "����":     "����ʦ���İ�Ů��",
           "��ҩʦ":   "��Ҫ�ݷü�ʦ��",
            "job" : (: ask_job() :),
            "ʧ��" : (: ask_fail() :),
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say �����书���������ɽݡ�");
           command("say ��λ"+RANK_D->query_respect(ob)+"�����ǰ�������ׯһ���ˡ�");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say �����ڽ���������������"+ RANK_D->query_respect(ob)+"��ذɡ�");
           return;
        }
        if (ob->query("gender") == "����")
        {
           command("say ʦ�������᲻�в�Ů�Ķ����ˣ���λ"+RANK_D->query_respect(ob)+"�Ͽ���ɡ�");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say ʦ�����ɮ�ֵ��ˣ���λ"+RANK_D->query_respect(ob)+"������ذɡ�");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say �һ���ֻ�ն����������ӣ���λ"+RANK_D->query_respect(ob)+"�Ƿ�ȥ������������");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "�������£���Ŭ�����顣");
        command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
        command("wield jian");
}
int accept_object(object who, object ob)
{
	int exp;
	if (query_temp("jinbing") < 0)
	{
                command("say " + RANK_D->query_respect(who) + "�Һ��ۣ����ͷ�������Ͱɡ�");
		return 0;
	}
//        if(ob->query("userp")) return notify_fail("�ٺ٣������ף���\n");
	if (strsrch(ob->query("name"), "���տ���ͷ­") < 0 &&
	    strsrch(ob->query("name"), "���պ��ҵ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ŷ�����ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ŷ���˵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "��������ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����̵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�������˵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ɳͨ���ͷ­") < 0 &&
	    strsrch(ob->query("name"), "��ͨ����ͷ­") < 0 &&
	    strsrch(ob->query("name"), "����յ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����ҵ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����۵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "Ǯ�ཡ��ͷ­") < 0 &&
	    strsrch(ob->query("name"), "������ͷ­") < 0 &&
	    strsrch(ob->query("name"), "����µ�ͷ­") < 0) 
	{
                command("say ������Щ������ʲô�ã�\n");
		return 0;
	}
       if(ob->query("userp"))
	{
                command("say �ٺ٣������ף���\n");
		return 0;
	}
	else
	{
                command("say ��������һֱ��ɱ��Щ�𹷣�л������ˡ�");
	}
	exp = 20+random(30);
	this_player()->add("combat_exp",exp);
	add_temp("jinbing", -1);
	tell_object(who,HIW"½�˷罱������"+chinese_number(exp)+"��ʵս����\n"NOR);
	return 1;
}

int ask_job()
{

        object me = this_player();
        object ob = this_object();
	  
        if( me->query("family/family_name") != "�һ���")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
	                      return 1;
            }

//	  if (ob->query_condition("taohuajob"))
//           {
//                      message_vision("$N����$n˵������һ������,������ʮ�����һ��!\n", this_object(), me);
//	                      return 1;
//            }

      if( (int)me->query_skill("bibo-shengong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("½�˷����$Nҡ��ҡͷ˵����Ȼ�����!\n", me);
                      return 1;
            }
        if ((int)me->query_condition("taohuajob"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����սӹ�����,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�㻹�����߾���������");
                return 1;
}
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ���Ǳ��̫����!!");
                return 1;
        }

        if (me->query("taohuajob") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "�����һ���ٴ�,Ҫ·���˵ء�");
                command("say " + me->query("id") + "��ѹٴ��ϵ�̰��ɱ��,�ѽ������������˷��ˣ�\n" NOR);
                me->set("taohuajob", 1);
//	        ob->apply_condition("taohuajob",13);
	        me->apply_condition("taohuajob",16);
                return 1;
               }                              
}


int ask_fail()
{
        object me = this_player();
        
        if (me->query("taohuajob") == 1) {
                command("sigh");
                command("say ��������Ҳ�����ٴ�,����150��EXP.");
                me->add("combat_exp",-150);
                me->delete("taohuajob");
                me->apply_condition("menpai_busy",12);
//                call_out("delete", 1);
                return 1;
                }
}



int hit_ob(object me, object ob, int damage)
{
if (ob!=me)
{
ob->start_busy(12);
	ob->apply_condition("qx_snake_poison", 220);
	ob->apply_condition("wugong_poison", 140);
        ob->apply_condition("chanchu_poison", 140);
        ob->apply_condition("xiezi_poison", 140);
        ob->apply_condition("snake_poison", 140);
        ob->apply_condition("zhizhu_poison", 140);
        tell_object(ob, HIG "����ñ����еĵط�һ��������\n" NOR );
}
}