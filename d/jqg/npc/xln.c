// /u/dubei/gumu/npc/xln
// by dubei
inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("С��Ů", ({ "xiao longnv", "longnv" }));
        set("nickname", "�������");
        set("long", 
                "ӯӯ��վ��һλ�������׵�Ů�ӣ�����������һ��Ѫɫ���Եò԰��쳣��\n"
                "����һϮ��ɴ��İ��£����������������\n");
        set("gender", "Ů��");
        set("age", 17);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 40);
        set("double_attack", 1);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("eff_jingli", 3000);
        set("jiali", 150);
        set("combat_exp", 2000000);
        set("shen", 25000);
        set("chat_chance_combat", 10);
//       set("chat_msg_combat", ({
//                (: perform_action, "sword.xuan" :),
//        }));
        set_skill("force", 300);
        set_skill("yunv-shenfa", 300);
        set_skill("dodge", 300);
        set_skill("yunv-xinfa", 300);
        set_skill("cuff", 300);
        set_skill("meinv-quan", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
//        set_skill("taoism", 200);
        set_skill("strike", 300);
        set_skill("literate", 300);
        set_skill("yunv-jian", 300);
        map_skill("force", "yunv-xinjing");
        map_skill("dodge", "yunv-shenfa");
        map_skill("cuff", "meimu-quanfa");
        map_skill("parry", "yunv-jian");
        map_skill("sword", "yunv-jian");
  
        create_family("��Ĺ��", 2, "�������");
        setup();
//	carry_object("/clone/weapon/changjian")->wield();
      carry_object("d/gumu/npc/obj/baipao")->wear();
	carry_object("/clone/misc/cloth")->wear();
//        carry_object("/clone/armor/wcloth")->wear();
 carry_object(__DIR__"snj")->wield();

}

 
      
