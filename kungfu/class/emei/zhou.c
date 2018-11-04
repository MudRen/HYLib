// zhou.c ������

#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int ask_zhang();
int ask_emei();

void create()
{
        set_name("������", ({ "zhou zhiruo","zhiruo","zhou"}));
        set("long",
                "���Ƕ����ɵĵ��Ĵ����ŵ��ӡ�\n"
                "һ�����������ס�����һ�������ѡ�\n"
                "�����������Ц�д���Щ�����Ρ�\n"
                "���ܼ�į��\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "���"    : "������ȣ����԰ɡ�",
                "����"    : "Ҫ�������ҵ�ʦ����ȥ��",
                "����"    : "���ġ�����Ҳ���ң�",
                "����"    : "��Ҫ���������ӣ�",
                "���콣"  : "ʦ������������ʦ��ˡ�",
                "������"  : "�������ֳ��ۣ��������ˡ�",
                "���ʦ̫"  : "ʦ���ѵ���ͽ�����Ȱͽ��Ұɡ�",
                "���޼�"  : (: ask_zhang :),
                "������"  : (: ask_emei :),
        ]));
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 13500);
        set("jing", 12000);
        set("max_jing", 12000);
        set("neili", 13500);
        set("max_neili", 13500);
        set("jingli", 12000);
        set("max_jingli", 11000);

        set("combat_exp", 3500000);
        set("score", 1000);
        set_skill("persuading", 280);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("claw", 100);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 200);
        set_skill("jiuyin-baiguzhao", 300);
        set_skill("tiangang-zhi", 200);
        set_skill("huifeng-jian", 290);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 320);
        set_skill("feiyu-bian", 200);
        set_skill("bagua-dao", 180);
        set_skill("bagua-zhang", 180);

        set_skill("huixin-strike", 380);
        set_skill("piaoxue-hand", 380);
        set_skill("yinlong-whip", 380);
        set_skill("yitian-jian", 380);
        set_skill("whip", 220);
        set_skill("hand", 220);
        
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        map_skill("whip","yinlong-whip");

	        map_skill("hand","piaoxue-hand");
        map_skill("strike","huixin-strike");
        map_skill("parry","yinlong-whip");
        map_skill("sword","yitian-jian");
        prepare_skill("strike", "huixin-strike");
        prepare_skill("hand", "piaoxue-hand");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "whip.duoming" :),
                (: perform_action, "whip.zhu" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "strike.gu" :),
                (: perform_action, "hand.yun" :),
                (: perform_action, "hand.zhao" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );

        create_family("������", 4, "���ŵ���");

        setup();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/d/emei/obj/ycloth.c")->wear();
}

void attempt_apprentice(object ob)
{

   if (ob->query("shen")<100)
   {
       command("heng");
       command("say " + ob->query("name") + "������ʲô������͵�������ݣ����������ޣ�");
       command("!!! " + ob->query("id"));
       kill_ob(this_player());
   }
   else
      if ( ob->query_temp("marks/�η���") )
      {

        if ((int)ob->query("per") < 22 )
        {
            command("giggle");
            command("say ��λ"+RANK_D->query_respect(ob)+"��ò̫Ҳ...������������ذɣ�");
           return ;
        }
        if ((int)ob->query_dex() < 26  && (int)ob->query_int() < 28 )
        {
           command("say ��λ"+RANK_D->query_respect(ob)+"�������ʲ���һ�㡣");
           command("say �����д���Ǳ���������Ȼ�ȥĥ��ĥ����");
           return ;
        }
        command("say" + ob->query("name") + "������ô��������Ϊ����������ɡ�\n");
        command("recruit " + ob->query("id"));
        ob->delete_temp("marks/�η���");
      } 
      else command("say " + this_player()->query("name") + "��û�¾Ϳ������ˡ�\n\n");
   return;
}

int ask_zhang()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") >= 2 ) {
        command("blush");
        command("say ��Ȼ���Ѿ����Ĳ���ϲ������������Ӱ����ʱ�޿̲��������ҵ��Ժ��");
        command("say ���վ�������ƭ�Լ�����������ƭʦ����ʦ���̸��ҵ��������������ܺ͹�����ɵ��뷨�վ��ǲ���ʵ���ˡ�");
        command("sigh");
        me->set_temp("jiuyin/emei", 3 );
        return 1;
    }
    return 0;
}

int ask_emei()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") >= 3 ) {
        command("say ��Ȼ����㵽��ʦ������ѯ���������������ܰɡ�");
        command("say �����ҵ�ϣ��ֻ�ܼ��������ˡ�");
        command("sigh");
        me->set_temp("jiuyin/emei", 4 );
        return 1;
    }
    return 0;
}
