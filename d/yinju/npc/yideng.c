// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("һ�ƴ�ʦ", ({"yideng dashi", "dashi", "yideng"}));
	set("nickname", HIG "����һ��" NOR );
    set("gender", "����");
    set("age", 52);
	set("long", 
		"�����Ǻųơ��ϵۡ���һ�ƴ�ʦ�����������ˣ�����ѷλΪɮ��\n"
		"�����ֲ�ɮ�ۣ����������İ�ü���۽Ǵ�����������Ŀ���飬\n"
		"���봹�磬ü����������࣬��һ��Ӻ�ݸ߻�����ɫ��ȴ��һ\n"
		"����֪����ʦһ�����ƣ��������\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 60);

    set("qi", 23000);
    set("max_qi", 23000);
    set("jing", 15000);
    set("max_jing", 13000);
    set("neili", 60500);
    set("max_neili", 60500);
    set("jiali", 100);
	
    set("combat_exp", 9500000);
    set("score", 0);
	 
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("cuff", 250);
        set_skill("strike", 250);
        set_skill("sword", 250);
        set_skill("staff", 250);
        set_skill("finger", 380);
        set_skill("buddhism", 500);
	set_skill("kurong-changong", 380);
        set_skill("tiannan-step", 380);
        set_skill("jinyu-quan", 380);
        set_skill("wuluo-zhang", 380);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 380);
        set_skill("feifeng-whip", 380);
        set_skill("sun-finger", 380);
	set_skill("six-finger", 380);
	set_skill("sun-finger", 380);
	set_skill("literate", 320);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("unarmed", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");
if (random(2)==0)
{
	map_skill("finger", "six-finger");
	prepare_skill("finger", "six-finger");
}
//	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.sandie" :),
                (: perform_action, "unarmed.dian" :),
                (: perform_action, "unarmed.jian" :),
                (: perform_action, "unarmed.qian" :),
                	 (: perform_action, "unarmed.dragon" :),

                (: perform_action, "finger.liumaijingshen" :),
                (: perform_action, "finger.qi" :),
                (: perform_action, "finger.zong" :),
                (: perform_action, "finger.zongheng" :),
                	
                  (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);

    create_family("����μ�", 16, "����");
    setup();

    carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{       
        string oldtitle;
	oldtitle = ob->query("title");
        if (!oldtitle) return;

        if( ob->query("family/family_name") != "����μ�")
           {
		command("say �����Ѿ��������������㽭�����񣬲�����ͽ�ˡ�\n");
                      return;
            }

	if (strsrch(oldtitle, "�������������佫")< 0)
  	{
   	if (strsrch(oldtitle, "��������������ū")< 0)
        {
		command("shake "+this_player()->query("id"));
		command("say �����Ѿ��������������㽭�����񣬲�����ͽ�ˡ�\n");
		return;
	}
	}
       if ((int)ob->query("shen") < 10000) {
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
          if (ob->query_temp("give_bunan") != 1)
       {
                command("sigh "+this_player()->query("id"));
		command("say ������Ȼ�Ѿ�������"+ RANK_D->query_respect(ob) +
            "�Ƿ��ܰ����Ŀ���Ӣ�����ڽ�����Ρ�\n");
		return;
       }
        command("chat �벻�������ڴ���֮�꣬���ٵ�һ������֮�ţ������븮���㵱���ұ�����");
	command("recruit " + ob->query("id"));
        ob->set("title","����������������");

	
}
int accept_object(object who, object ob)
{
   if (ob->query("id")=="bu nan")
   {
      who->set_temp("give_bunan",1);
      command("say Ӣ�ã�ԭ���㻹�벻ͨ...��...");
      return 1;
   }
else
	message_vision("һ����ü��$N˵��ʩ����ذɡ�\n", who);
        return 0;
}

    
 

