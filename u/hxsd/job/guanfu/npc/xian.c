//  xian ����ͨ
 
inherit NPC;
 
void create()
{
	set_name("����ͨ", ({ "xian yutong", "xian" }));
	set("nickname", "��ɽ��ͽ");
	set("long", 
        "����üĿ���㣬��������������ʵ�����Ǹ����ݴ������ˡ�\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen", -5000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 360000); 
	 
         set_skill("force", 100);
         set_skill("hunyuan-yiqi", 100);
         set_skill("dodge", 110);
  

        set_skill("shaolin-shenfa", 110);
        set_skill("strike", 130);
        set_skill("parry", 120);
        set_skill("literate", 100);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "kunlun-zhang");
  	prepare_skill("strike", "kunlun-zhang"); 
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
