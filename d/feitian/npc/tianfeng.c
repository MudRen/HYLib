#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
        set_name("���ʮ����", ({ "master tianfeng", "tianfeng", "master"}) );
        set("gender", "����" );
        set("age", 55);
        set("nickname", CYN "��������" NOR);
        set("long", 
"һ����ɫ���ƣ�Ũü��ȧ���������ߣ�������ɱ��������ϥ����ɽ��֮�ϣ�
�¾���¶�����㣬ȴ��һ˫�߳���ľ��ľ��˷���ǰ��ľ���Ͼ��ַ��ű���
�ʳ�����\n");
    create_family("����������", 5, "�Ҷ�");
    set("rank_nogen",1);
    set("ranks",({"����","����","����",RED"��ɲ"NOR,HIR"����"NOR}));
    set("rank_levels",({32000,512000,1536000,3456000 }));
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

         set_skill("wuxing-dun",280);
        set_skill("shayi",280);
         set_skill("aikido",280);
         set_skill("shayi-xinfa",320);
        set_skill("shiren-jianfa",280);
        set_skill("shiren-quanfa",280);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",180);

set_skill("xuanhualiu-quanfa",280);
set_skill("ninjitsu",380);
set_skill("ittouryu",380);
set_skill("enmeiryu",380);
set_skill("hand",320);
        set_skill("literate",250);
        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        
        map_skill("hand", "enmeiryu");
        map_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("hand", "enmeiryu");
        
        create_family("����������", 5, "�Ҷ�");
         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "hand.mukuha" :),
                (: perform_action,"hand.shiden" :),
                (: perform_action, "hand.shimon" :),  
                (: perform_action, "hand.chuyao" :), 
                (: perform_action, "hand.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                        "���ʮ������ب�Ų��������ɫ����ͻȻ�����������۵�һ���ȳ�����Ѫ��\n",
                                })  );
        set("inquiry",  ([
                "���" : "���ӡ������ӡ��������������\n",
                ])              ); 
        setup();
    carry_object(__DIR__"wucloth")->wear();
    carry_object(__DIR__"muji")->wear();
        carry_object(__DIR__"blackblade")->wield();
} 
void attempt_apprentice(object ob)
{
        if(ob->query("family/family_name")!="����������")
        {
                command("say ������ʱ����??\n");
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
	ob->set("title",HIR"��һ������"HIR"����"NOR);
       ob->set("class", "yujianliu");
}