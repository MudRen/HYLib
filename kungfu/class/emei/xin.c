// xin.c ����ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����ʦ̫", ({ "jingxin shitai","jingxin","shitai"}));
        set("long",
      "����һλ������ҵ��ã����ڸ�£����ü��Ŀ��\n");
        set("gender", "Ů��");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "bonze");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 20);

                 set("max_qi", 6000);
        set("max_jing", 6500);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 650000);
        set("score", 1000);
        set_skill("persuading", 180);
        set_skill("throwing", 160);
        set_skill("force", 160);
        set_skill("dodge", 170);
        set_skill("finger", 175);
        set_skill("parry", 170);
        set_skill("strike", 160);
        set_skill("sword", 180);
        set_skill("literate", 170);
        set_skill("mahayana", 160);
        set_skill("jinding-zhang", 160);
        set_skill("tiangang-zhi", 165);
        set_skill("huifeng-jian", 160);
        set_skill("zhutian-bu", 160);
        set_skill("linji-zhuang", 160);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        set_skill("yanxing-dao", 380);
        set_skill("bagua-dao", 380);
        set_skill("bagua-zhang", 380);
        map_skill("blade","bagua-dao");
        map_skill("parry","bagua-dao");
        
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");	
set_temp("huifeng/jue",1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "blade.feiyan" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.mang" :),
                (: perform_action, "blade.sha" :),                	
                (: perform_action, "blade.tian" :),                	                	                	
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                	(: perform_action, "sword.jue" :),
                	(: perform_action, "sword.liaoyuan" :),                		
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );


        create_family("������", 4, "����");

        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}
void attempt_apprentice(object ob)
{
    command ("say �����ӷ�ƶ�᲻�յ��ӡ�\n");
    command ("say ���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�\n");
    return;
}
