// hehongyao.c
// �κ�ҩ
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�κ�ҩ", ({ "he hongyao", "he" }));
        set("nickname", HIG "����ؤ��" NOR);
        set("long",@LONG
�������嶾�̵ĳ��ϣ������Ĺùúκ�ҩ����Ȼ�ǽ����ĳ�����������ȴ��һ���
�ϴ�����ѧ�ġ���˵����������Ϊ�����̳��ˣ����������´�����Ա������˴�
����ʥ�أ�����ǰ�������һ���ƾɵ������������̺ۣ����ù������˫Ŀ��
����Թ��֮ɫ��
LONG
        );
        set("title","�嶾�̳���");
        set("gender", "Ů��");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 16000);
        set("max_jing", 16000);
        set("neili", 24000);
        set("max_neili", 24000);
        set("jiali", 100);
        set("combat_exp", 7000000);
        set("score", 500000);

        set_skill("force", 200);
        set_skill("wudu-shengong", 320);
        set_skill("dodge", 190);
        set_skill("wudu-yanluobu", 250);
        set_skill("unarmed", 160);
        set_skill("qianzhu-wandushou", 260);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 380);
        set_skill("poison", 160);
        set_skill("duji", 300);
        set_skill("literate", 80); 
        set_skill("finger",160);
        set_skill("shedu-qiqiao",360);
//      set_skill("hammer", 100);
//      set_skill("jinshe-chui", 150 );
//      set_skill("huoyan-dao", 200);


        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//      map_skill("hammer", "jinshe-chui");
//      map_skill("strike","huoyan-dao");
         set("chat_chance_combat", 90);
         set("chat_msg_combat", ({
                (: perform_action, "sword.suo" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "dodge.snake" :),
                 (: perform_action, "dodge.snake" :),
                (: exert_function, "recover" :),
        }) );


        create_family("�嶾��", 11, "����");

        setup();

        carry_object(__DIR__"obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object(__DIR__"obj/wuxing");

        add_money("gold",1);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  }

                  if ((int)ob->query("shen") > -10000) {
                                 command("say �����嶾�̵��ӱ����ĺ�������");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ĵ�������ϧ���ҽ�û��Ե�ְ���");
                return;
                  }

        if ((string)ob->query("family/family_name") != "�嶾��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���Ǳ��̵��ӣ�������ذɣ�");
                return;
                  }

        if ((int)ob->query_skill("poison", 1) < 100) {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 100) {
                command("say ����嶾�񹦻�ѧ�Ĳ�������");
                return;
        }

          command("chat �ٺٺٺ٣���������");
          command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
          command("chat �ٺٺٺ٣���������");
          command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title","�嶾�̻���");
       return;
}

