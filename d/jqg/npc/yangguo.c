// /u/dubei/gumu/npc/yangguo
// by dubei
inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
string ask_me();
void create()
{
        set_name("���", ({ "yang guo", "yang" }));
        set("nickname", "�����");
        set("long", 
                "�����������������һ����񳿡������ף���ü���ޣ�����������\n"
                "��Ȼ��ֻ��һֻ�첲�����ǿ�ΰ����������˸о�Ӣ�����ˡ�\n");
        set("gender", "����");
        set("age", 32);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("eff_jing", 3000);
        set("jiali", 100);
        set("combat_exp", 2500000);
        set("shen", 25000);
          set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
          (: perform_action, "strike.xiaohun" :),
          (: perform_action, "sword.xunlei" :), }));
        set_skill("force", 300);
        set_skill("yunv-shenfa", 300);
        set_skill("dodge", 300);
        set_skill("yunv-xinfa", 300);
        set_skill("cuff", 300);
        set_skill("meinv-quan", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("xuantie-jianfa", 300);
        set_skill("taoism", 300);
        set_skill("strike", 300);
        set_skill("literate", 300);
        set_skill("anranxiaohun-zhang", 300);
        set_skill("yunv-jian", 300);
        map_skill("force", "yunv-xinfa");
        map_skill("dodge", "yunv-shenfa");
        map_skill("cuff", "meimv-quan");
        map_skill("parry", "anranxiaohun-zhang");
        map_skill("sword", "xuantie-jianfa");
        map_skill("strike", "anranxiaohun-zhang");
        prepare_skill("strike", "anranxiaohun-zhang");
             set("inquiry", 
                ([
                           "����֮��" : (: ask_me :),
              ]));
        create_family("��Ĺ��", 2, "�������");
        setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"jzj")->wield();
}

string ask_me()
{ 
       mapping fam; 
       object ob;
       ob = this_player();
//       if (!(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��")
//               return RANK_D->query_respect(this_player()) + 
//               "���ҹ�Ĺ����,��֪���˻�����?";
            if (!ob->query_temp("xth_hm"))
            return RANK_D->query_respect(this_player()) + 
               "��֪��ʲ������֮����?";
                      ob->delete_temp("xth_hm");
               ob->set_temp("make/xtj_look1",1);
            ob->set_temp("yg_pbask",1);
       return "������Ϣ,��������,˫�����,���ص���,�����ں�ˮ�������ľ���,��ú�ȥ����һ��.";
}

void kill_ob(object me)
{
        command("chat* nomatch " + me->query("id"));
        
        ::kill_ob(me);
}
      
