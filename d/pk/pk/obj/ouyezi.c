// npc: /d/npc/m_weapon/npc/tianjianshi.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;

string ask_met();
int do_weapon();
object creat_weapon();

void create()
{
        set_name("ŷұ��", ({ "ouye zi", "zi" }) );
        set("nickname", RED "���Ľ���" NOR );
	set("gender", "����" );
        set("age", 60);
        set("long", 	
            "��ͷ�ϰ���ͷ�����Ƴ���Ʈ����ǰ����Ŀ���ݵ������й⣬\n"
            "��Ŀ��������˸˸���ž��������ݵĽ��⣬�����ƺ�����Χ\n"
	    "��һ�ɽ���֮�С�\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
	set("max_neli",5000);
	set("jiali",50);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("claw",200);
        set_skill("jiuyin-baiguzhao",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo-shengong",100);
        set_skill("luoying-shenjian",100);
        set_skill("parry",90);
        set_skill("anying-fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);

	create_family("������",1,"����");

        set("combat_exp", 250000);
	set("score",0);
	
        map_skill("force","bibo-shengong");
	map_skill("parry","luoying-shenjian");
	map_skill("sword","luoying-shenjian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","anying-fuxiang");

	
	set("attitude", "peaceful");
        
	set("inquiry", ([
            "����"  : "�������Ǽ�ʮ�ּ����£�Ҫ�����˵ľ��������������о��ĺ�������\n",
	    "ԭ��"  : "��������ǧ���������������ҵ����Ҳ��ܰ���������\n",
	    "����"  :  (: ask_met() :),
       ]) );

        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
             "ŷұ�Ӹ������裺��������⣬�����͡����������⣬��Ӣ�ۣ�\n",
	     "ŷұ�ӵ�ͷ�������ƺ���˼��ʲô��\n"
	     "ŷұ��̾��һ�����������Ӣ�ۣ���Ӣ�ۡ�����������\n"
       }) );
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}




string ask_met() 
{ 
	object weapon;
	object gold;
	object *inv;
	int i;
        object me = this_player(); 
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
        if((int)(inv[i]->query("weapon_prop")&&inv[i]->query("ownmake")))
        return "�����ϲ�����������"; 


        if(me->is_busy())
        return "����һ��������û����ɡ�";

//        gold = present("gold_money", this_player());
//        if( !gold) return "������û�н��ӡ�";

//        if((int) gold->query_amount() < 101)
//        return "������û����һ�������ӡ�";

	if (me->query("weapon/type")) {
		switch((string)me->query("weapon/type"))
		{
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_sword");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
                        return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_blade");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_whip");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_staff");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_club");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "�޺���,��quit,�����µ�½һ��!"; 
		}
          }
else return "�����������"; 
}

}