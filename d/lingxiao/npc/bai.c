//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������",({"bai zizai","bai"}));
        set("nickname", HIC"��������"NOR);
        set("gender", "����");
        set("age", 55);
        set("long", 
             "������ѩɽ���ɵ������ˣ�ϰ����ԣ�����Ϊ�����书��һ,\n"
             "����Լ��ʮ���꣬�����ܸɣ�������������һ�\n");
        set("attitude", "peaceful");

        set("str", 55);
        set("con", 55);
        set("int", 50);
        set("dex", 50);
        set("per", 55);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jing", 18000);
        set("max_jing", 18000);
        set("qi", 18000);
        set("max_qi", 18000);
        set("jiali", 100);
        set("inquiry", ([
            "ʯ����"   : "������Ҵ������С���˵�,�ҷǰ�������Ƥ���ɡ�",
        ]) );

        set("combat_exp", 8000000);
        set("shen_type", 1);
        set("score", 100000);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 250);
        set_skill("sword", 380);
        set_skill("force", 320);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("literate", 200);

        set_skill("xueshan-sword", 380);
        set_skill("bingxue-xinfa", 380);
        set_skill("snow-zhang", 380);
        set_skill("snowstep", 380);


         set_skill("doom-hand", 380);
        set_skill("hanshan-strike", 380);
        set_skill("snowwhip", 380);
        set_skill("hand", 280);
        set_skill("strike", 280);
        set_skill("whip", 280);
set_skill("mingyu-gong", 380);


        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");
        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
if (random(3)==0)
{
        map_skill("sword", "mingyu-gong");
        map_skill("parry", "mingyu-gong");
        map_skill("force", "mingyu-gong");
        map_skill("unarmed", "mingyu-gong");
        map_skill("dodge", "snowstep");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.gua" :),
                (: perform_action, "unarmed.moqi" :),
                (: perform_action, "unarmed.qiong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "zu" :)                	
        }) );	
	
}
else
{
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");
	
}

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("������", 5, "����");
        setup();

        
        carry_object("/d/lingxiao/obj/icesword")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say ����������,Ҳ����˼�����ң�");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 80 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
    } 
    if ((int)ob->query("shen") < 50000 ) {
         command("say �������������������˾��ӣ��������㡣"); 
                return;
    } 
    if ((int)ob->query("max_neili") < 800 ) {
         command("say ���������㣬�����������񹦵ľ��"); 
                return;
    }
    if ((int)ob->query_skill("xueshan-sword",1) < 100 ) { 
        command("say ��ı��Ž���̫����,����������ԭ����ʦ����߰�!"); 
                return;
    }
    if ((int)ob->query_skill("sword",1) < 100 ) {  
        command("say ��Ļ�������̫����,��������߻�������!"); 
                return; 
    }
    command("say �ܺã��ܺ�,���ӽ��������,��������ɡ�");
    command("say ���������û������ˣ�����Ȱ��ҹ��Űɡ�");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", HIW"�����ǳ���"NOR); 
}

