// /kungfu/class/xueshan/fawang.c  ���ַ���
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        object ob;
        set_name("���ַ���", ({ "jinlun fawang", "fawang", "fawang" }));
        set("long",@LONG
����ѩɽ�µĻ��̷�������ѩɽ�µĵ�λ�������������Ħ�ǡ�
��һ���Ϻ����ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 60);
        set("int", 60);
        set("con", 60);
        set("dex", 60);
        set("max_qi", 18000);
        set("max_jing", 18000);
        set("neili", 54500);
        set("max_neili", 54500);
        set("jiali", 100);
        set("combat_exp", 9500000);
        set("score", 200000);

        set_skill("necromancy", 380);
        set_skill("xiaowuxiang", 380);
        set_skill("force", 280);
        set_skill("longxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 250);
        set_skill("literate", 200);
        set_skill("hammer", 380);
        set_skill("riyue-lun", 380);
	set_skill("dashou-yin", 380);
        set_skill("staff", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}
	set("inquiry", ([
		"ʮ����������" : "���Ǳ��ŷ𱦣��������׸��㣬�����ɰ�����һ��غ컨�ɣ�\n",
	]));

        create_family("ѩɽ��", 2, "���̷���");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        if (clonep()) {
                if (random(4)==0)
{
                ob = new(__DIR__"13jiasha");
                ob->set("jiasha/neili",13);
                ob->move(this_object());
                ob->wear();
}
}

        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",1);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ�����塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("class") != "bonze") {
                command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("family/family_name") != "ѩɽ��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
                  }

        if ((int)ob->query_skill("lamaism", 1) < 80) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

        command("smile");
        command("nod");
        command("say �������ѧϰ�𷨰ɣ�");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY"���"NOR);
}
int accept_object(object ob, object obj)
{
       if(!ob||environment(ob)!=environment() ) return 0;
       
       if(!objectp(ob) ) return 0;
 
       if( !present(obj,ob) )
        { 
         say("�����𣿣�\n");
         return 1;
        }  

        if(obj->query("id")=="zang honghua")
{
        if( present("shisan longxiang",this_object()) )
{
obj->set("no_get",1);
command("say ̫���ˣ��غ컨����ѩɽһ����!");
command("remove shisan longxiang");
command("say ���ʮ���������ľ��͸��㻤��֮�ðɡ�");
command("give shisan longxiang to "+ob->query("id"));
}
else command("say ��ɮ�����޳���治֪����ôлл��!");
        return 1;
}
}
