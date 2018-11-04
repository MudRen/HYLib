// lin.c �ֳ�Ӣ
// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

string ask_yunv();

void create()
{
        set_name("�ֳ�Ӣ", ({"lin chaoying", "lin"}));
        set("gender", "Ů��");
        set("age", 42);
        set("long",
                "�����ǹ�Ĺ�ɵĿ�ɽ��ʦ�ֳ�Ӣ����Ȼ�Ѿ�����ʮ���ˣ���֮ȴ\n"
                "����ͬ��ʮ��ͷ����������ȫ���������������һ�Գ��İ��£�\n"
                "ֻ��ϧ��Ե�޷ݣ�ֻ�ö��������Ĺ���ľӡ�\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 87);
        set("int", 82);
        set("con", 85);
        set("dex", 82);

        set("chat_chance_combat", 99);
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
        set("chat_chance", 99);
        set("chat_msg", ({
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));

        set("qi", 26000);
        set("max_qi", 26000);
        set("jing", 30400);
        set("max_jing", 32400);
        set("neili", 59000);
        set("max_neili", 59000);
        set("jiali", 100);

        set("combat_exp", 9600000);
        set("score", 0);

        set_skill("force", 320);
        set_skill("throwing", 300);
        set_skill("whip", 380);
        set_skill("yinsuo-jinling", 380);
        set_skill("yunv-xinfa", 380);    //��Ů�ķ�
        set_skill("sword", 250);
        set_skill("yunv-jian", 380);     //��Ů��
        set_skill("quanzhen-jian",320);  //ȫ�潣
        set_skill("dodge", 360);
        set_skill("yunv-shenfa", 380);   //��Ů��
        set_skill("parry", 250);
        set_skill("unarmed",250);
        set_skill("qufeng",320);         //����֮��
        set_skill("meinv-quan", 380);    //��Ůȭ��
        set_skill("literate",220);
        set_skill("taoism",320);
        set_skill("strike",320);
        set_skill("tianluo-diwang",380);         //����֮��

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("��Ĺ��", 1, "��ɽ��ʦ");


        set("book_count",1);
        set("inquiry", ([
                "������" :  "�󵨺�С�ӣ�Ҳ��ֱ��������ʦ֮����\n",
                "������ʦ" : "������ȫ��̵��ƽ̣��Ժš������ˡ���\n",
                "��Ĺ��" :  "�ǰ������������һ�ִ��µĹ�Ĺ��\n",
                "��Ů�ľ�" : (: ask_yunv :),
        ]) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/qingyi")->wear();

}

void attempt_apprentice(object ob)
{
        if (ob->query_int() < 30) {
                command("say �ҹ�Ĺ�ɵĹ����һ�����֣�������ʲ�����");
                return;
        }
        if ((int)ob->query_skill("yunv-xinfa",1) < 300 ) {
                command("say �����Ů�ķ������,�������Ը�������书��");
                return;
        }
        command("say �ðɣ�����Ҳ���������ˣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_yunv()
{
        mapping fam;
        object ob;
        int lvl_yunv;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "��Ĺ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾�ɺ��޹ϸ𣬺��������ɵ��ľ���";
        if (!(lvl_yunv = this_player()->query_skill("yunv-xinfa",1))
            || lvl_yunv < 55)
                return RANK_D->query_respect(this_player()) +
                "����Ů�ķ�����㣬�Ҳ��ܽ���Ů�ľ�������";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ���Ů�ľ��Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing2");
        ob->move(this_player());
        return "�ðɣ��Ȿ����Ů�ľ������û�ȥ�ú��ж���";
}
