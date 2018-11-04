//xln.c С��Ů
#include <ansi.h>
inherit NPC;
 
void create()
{
        set_name("СС��Ů", ({ "xiao longnu", "xiao", "longnu" }));
        set("title","��Ĺ����");
        set("nickname",HIC"��Ů����"NOR);
        set("long", "�������쳣����Ҳ���ǳ��ӹ�Ĺ֮�ʣ���ɫ�԰ס�\n");
        set("gender", "Ů��");
        set("age", 39);
        set("attitude", "friendly");
        set("per", 40);
        set("str", 24);
        set("dex", 23);
        set("con", 20);
        set("int", 24);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),

        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "С��Ů���ĵص�������֪����������������п����Ҵ��������ϵ��֣���\n", 
                "С��Ů�૵�������Ů����ȫ�潣�ϱڣ��ǿ������޵С�����...����ȥ����һ�����أ���\n",
                "С��Ů�����̾�˿�����ת��ͷȥ��\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));

        set("qi", 6500);
        set("max_qi", 6500);
        set("jing", 6600);
        set("max_jing", 6600);
        set("neili", 14000);
        set("max_neili", 24000);
        set("jiali", 200);

        set("combat_exp", 2000000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("throwing", 300);
        set_skill("whip", 260);
        set_skill("yinsuo-jinling", 260);
        set_skill("yangyanshu", 300);
        set_skill("yunv-xinfa", 250);    //��Ů�ķ�
        set_skill("sword", 150);
        set_skill("yunv-jian", 250);     //��Ů��
        set_skill("quanzhen-jian",130);  //ȫ�潣
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 260);   //��Ů��
        set_skill("parry", 150);
        set_skill("hubo", 120);          //˫�ֻ���
        set_skill("unarmed",150);
        set_skill("meinv-quan", 260);    //��Ůȭ��
        set_skill("literate",120);
        set_skill("qufeng",250);         //����֮��
        set_skill("wuzhan-mei",150);
        set_skill("strike",200);
        set_skill("tianluo-diwang",300);         //����֮��

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");


        setup();

        carry_object(__DIR__"obj/ys")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/rsg");
        carry_object(__DIR__"obj/badan");
}
