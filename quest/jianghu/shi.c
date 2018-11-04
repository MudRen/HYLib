//dadi.c ����ʹ
// [lsg 1999/11/24]

inherit NPC;
#include <ansi.h>;
void create()
{
        set_name(HIW"����"NOR, ({ "xuan du", "xuan", "du"}));
        set("title", HIC"���ֻ�����ʦ"NOR);
        set("gender", "����" );
        set("age", 82);
        set("str", 50);
        set("int", 25);
        set_temp("no_kill",1);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"�����µĻ�����ʦ�����������Ϊ����!\n");
        set("combat_exp", 2000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
	create_family("������", 35, "����");

	set_skill("force", 150);
	set_skill("whip", 170);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 180);
	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 190);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 150);
	set_skill("cibei-dao", 150);
	set_skill("damo-jian", 150);
	set_skill("fengyun-shou", 150);
	set_skill("fumo-jian", 150);
	set_skill("jingang-quan", 150);
	set_skill("longzhua-gong", 150);
	set_skill("luohan-quan", 150);
	set_skill("nianhua-zhi", 150);
	set_skill("pudu-zhang", 150);
	set_skill("qianye-shou", 150);
	set_skill("sanhua-zhang", 150);
	set_skill("weituo-gun", 150);
	set_skill("wuchang-zhang", 150);
	set_skill("xiuluo-dao", 150);
	set_skill("yingzhua-gong", 150);
	set_skill("yizhi-chan", 150);
	set_skill("zui-gun", 150);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chanrao" :),
                (: perform_action, "whip.fumoquan" :),
                            }) );
       

        setup();
	carry_object("/d/shaolin/obj/changbian")->wield();
        carry_object("/clone/cloth/cloth")->wear();

}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;


        if (who->query("shen") < 10000)
        {
                  tell_object(who,"�㲻��ȥ��������!\n");
                   return 0;
        }

        if (who->query_condition("jianghu_busy"))
        {
                  tell_object(who,"ʩ����Ϣһ��!�Ȼ�������!\n");
                   return 0;
        }

        if (ob->query("money_id"))
        {
                  tell_object(who,"ƶɮҪǮ��ʲô��??\n");
                   return 0;
        }
        if (ob->query("id")=="renwu shi")
        {
                  tell_object(who,"������������ʿ!\n");
                   return 0;
        }
        if (ob->query_temp("no_kill"))
        {
                  tell_object(who,"������������ʿ!\n");
                   return 0;
        }

        if( userp(ob) )
        {
             tell_object(who,"ƶɮ���ܶɴ���!\n");
             return 0;
        }

	if( !ob->is_character() ) {
        tell_object(who,"��ʩ����Ҫ��ƶɮ����Ц��\n");
        return 0;
        }

	if( ob->query_temp("hunby") != who->query("id"))
	{
        tell_object(who,"���˺�����ʩ�������ģ�\n");
        return 0;
        }

	if (ob->query("id") == "corpse")
	{
        tell_object(who,"ʩ����������������ƶɮһ�����˸�ʲô?\n");
        return 0;
        }

	if (ob->query("id") == "skeleton")
	{
        tell_object(who,"ʩ����������������ƶɮһ�����˸�ʲô?\n");
        return 0;
        }

	if (ob->query("shen") > 0)
	{
        tell_object(who,"ʩ���������������������һ������!!\n");
        return 0;
        }

	if (ob->query("combat_exp") <= who->query("combat_exp")+100)
	{
        tell_object(who,"ʩ�������˺������ʵ���ǲ���Ϊ��!!\n");
        return 0;
        }

             tell_object(who,"ʩ����������ʵ�ڹ������������������¾ͽ���ƶɮ�ɣ�\n");
             exp = 150 + random(200);
             pot = 100 + random(100);
             score = 10 + random(5);
if ( who->query("combat_exp") > 1500000 )
{
             who->apply_condition("jianghu_busy",3);
             exp = exp/2;
             pot = pot/2;
             score = score/2;

}             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->apply_condition("jianghu_busy",3);
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
              who->add("shen", 50);
             who->set("score", bonus);
             tell_object(who,HIC"��ϲ���ֽ�����һ�����ˣ�\n"NOR);
             tell_object(who,HIG"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬\n"+ chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score)+"�㽭��������\n"NOR);
	if( ob->is_character() ) {
       call_out("destroying", 5,ob);                              
}
        return 1;
}

void destroying(object ob)
{   
   destruct(ob);
}