// hetieshou.c
// ������
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_box();

void create()
{
        set_name("������", ({ "he tieshou", "he" }));
        set("nickname", HIG "�嶾����" NOR);
        set("long",@LONG
��������һ��һ��ۺ�ɴȹ��Ц���绨����Ů�������ü���ѩ�ף�üĿ�续��
����һ˫���۵����㣬�ֽ��϶����������Ľ���˭���뵽�������嶾�̵Ľ�
�������֣�������ʿ�������޲������ľ���
LONG
        );
        set("title","�嶾�̽���");
        set("gender", "Ů��");
        set("age", 25);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
         set("per", 36);
        set("max_qi", 29000);
        set("max_jing", 29000);
        set("neili", 36000);
        set("max_neili", 36000);
        set("jiali", 100);
        set("combat_exp", 5500000);
        set("score", 500000);
        set("box_count",1);
        set("tieshao_count",1);

        set_skill("force", 300);
        set_skill("wudu-shengong", 380);
          set_skill("dodge",300);
          set_skill("wudu-yanluobu",380);
          set_skill("unarmed",300);
          set_skill("qianzhu-wandushou",380);
          set_skill("parry",300);
          set_skill("sword",300);
          set_skill("wudu-goufa",380);
          set_skill("poison",300);
          set_skill("literate",200);
          set_skill("finger",290);
          set_skill("shedu-qiqiao",380);
        set_skill("wudu-yanluobu", 380);
        set_skill("unarmed", 260);
        set_skill("qianzhu-wandushou", 380);
        set_skill("parry", 250);
        set_skill("duji", 300);
        set_skill("sword", 280);
        set_skill("wudu-goufa", 380);
        set_skill("poison", 380);
        set_skill("literate", 200);
        set_skill("finger",230);
        set_skill("shedu-qiqiao",380);
	set_skill("whip",500);
	set_skill("chilian-shenzhang",380);
	set_skill("jueqing-bian",380);
 	set_skill("ruanhong-zhusuo",380);
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
        map_skill("poison","shedu-qiqiao");
        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
map_skill("whip", "ruanhong-zhusuo");
//      map_skill("hammer", "jinshe-chui");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
         set("chat_chance_combat", 99);
         set("chat_msg_combat", ({
                (: perform_action, "whip.bohu" :),
                (: perform_action, "whip.pan" :),
                (: perform_action, "whip.teng" :),
                (: perform_action, "whip.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "dodge.snake" :),
                (: exert_function, "recover" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),		
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("�嶾��", 11, "����");

        setup();
        set("inquiry", ([
//              "name": "������������֮�ڶ�ʮ�������������Ҳ��\n",
                "�򶾿�": (: ask_me :),
                "����": (: ask_me :),
                "��ɳ��Ӱ": (: ask_box :),
         ]) );

carry_object("/kungfu/class/xingxiu/chanhunsuo")->wield();
        carry_object(__DIR__"obj/jingou");
        carry_object(__DIR__"obj/skirt")->wear();

        add_money("gold",1);
}
int ask_me()
{
        object ob;
        if ((string)this_player()->query("family/master_id")!="he tieshou"){
               command("say �򶾿��˱���ʥ�أ������̳���֮����˲��ý��롣");
               return 1;
         }
        if(query("tieshao_count")< 1 ){
              command("say �������ˣ��������Ѿ��������ˡ�");
              return 1;
        }
        command("say �򶾿��������쳣��ǧ��ҪС�İ���\n");
        command("say ��ֻ�������ҵ���������ƾ�����ɽ��붴�У�");
        ob = new("d/wudujiao/obj/tieshao");
        ob->move(this_player());
        add("tieshao_count",-1);
         remove_call_out ("give_tieshao");
         call_out ("give_tieshao", 900); // 15 ����
        return 1;
}
int ask_box()
{
       object ob;
       if ((string)this_player()->query("family/master_id")!="he tieshou"){
               command("say ���˱����ر������ײ�����˵ġ�");
               return 1;
        }
       if(query("box_count")< 1 ){
              command("say �������ˣ���ɳ��Ӱ���Ѿ��͸������ˡ�");
              return 1;
        }
       command("smile");
       command("say ��ô����Ҫ���˴���𣿿ɱ��������嶾�����簡��");
       command("say ��ɳ��Ӱ����ȥ�ɣ������ǳ��������嶾�̵�������");
       ob = new(__DIR__"obj/hanshasheying");
       ob->move(this_player());
       add("box_count",-1);
       ob->set("own_name",this_player()->query("id"));
        remove_call_out ("give_hssy");
        call_out ("give_hssy", 900); // 15 ����
       return 1;
}

void attempt_apprentice(object ob)
{

          if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  }

          if ((int)ob->query("shen") > 1000) {
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

        if ((int)ob->query_skill("poison", 1) < 120) {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 100) {
                command("say ����嶾�񹦻�ѧ�Ĳ�������");
                return;
        }

//        command("chat �ٺٺٺ٣���������");
          command("chat �ðɣ���Ȼ��˱���������������ͽ�ܡ�");
          command("chat ����һ�죬Ҫ�������˶�֪�������嶾�̵�����������");
        command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title","�嶾�̳���");
        return;
}
void give_hssy()
{
        set("box_count",1);
}
void give_tieshao()
{
        set("tieshao_count",1);
}

