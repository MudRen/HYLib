// wang.c ������
// By Lgg,1998.10

#include <ansi.h>

inherit NPC;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
        set_name("������", ({"wang chongyang", "wang"}));
        set("gender", "����");
        set("age", 66);
        set("class", "taoist");
        set("title",HIW"����ͨ"NOR);
        set("long",
                "������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ������������ˡ�������Ʈ\n"
                "Ʈ�����ۻ��䣬üĿ��񳣬����Щ�ɷ���ǵ�ζ����������һ\n"
                "ǻ��Ѫ����Ч���������������ϧ��͢���ܣ������Ļ����䣬\n"
                "�ִӵ��¾����������������Ĵ�����ִ�ȫ��̡�\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 75);
        set("int", 75);
        set("con", 75);
        set("dex", 75);
        set_temp("no_kill",1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
 (: exert_function, "hup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.tonggui" :),                
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "unarmed.kong" :),
                (: perform_action, "unarmed.luanwu" :),                	
                (: perform_action, "unarmed.quan" :), 	
                (: perform_action, "unarmed.ming" :), 		
                (: perform_action, "unarmed.ruo" :),                	                	

                (: perform_action, "unarmed.dang" :),
                (: perform_action, "unarmed.shen" :),                	
                (: perform_action, "unarmed.fen" :), 	
                (: perform_action, "unarmed.hun" :), 		
                (: perform_action, "unarmed.jian" :),                	                	

                (: exert_function, "shield" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "powerup" :),                     
    
        }));

        set("qi", 29500);
        set("max_qi", 29500);
        set("jing", 25500);
        set("max_jing",25500);
        set("neili", 69000);
        set("max_neili", 69000);
        set("jiali", 100);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
         set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);
        set("combat_exp", 8600000);
        set("score", 500000);
		set_skill("kongming-quan", 500);
	set_skill("kurong-changong", 500);
        set_skill("finger", 550);
        set_skill("yiyang-zhi", 550);
        set_skill("force", 500);
        set_skill("xiantian-qigong", 500);    //��������
        set_skill("sword", 550);
        set_skill("quanzhen-jian",500);  //ȫ�潣
        set_skill("dodge", 560);
        set_skill("jinyan-gong", 500);   //���㹦
        set_skill("parry", 500);
        set_skill("unarmed",500);
        set_skill("haotian-zhang", 500);    //�����
        set_skill("array",500);
        set_skill("qixing-array",500);
        set_skill("literate",520);
        set_skill("strike",550);
        set_skill("taoism",540);
        set_skill("finger",500);
        set_skill("sun-finger",500);  //һ��ָ
        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xiantian-qigong");
        map_skill("strike", "haotian-zhang");
        map_skill("finger","sun-finger");
        map_skill("unarmed","kongming-quan");
if (random(2)==0)	        map_skill("unarmed","xiantian-qigong");
        //prepare_skill("finger","sun-finger");
        //prepare_skill("strike","haotian-zhang");

        create_family("ȫ���", 1, "�ƽ�");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();

}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",HIG"���������\n\n"
		+ name() + HIG"����һ������ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void unconcious()
{
die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;
if (me==ob) 
{
me->set("qi",1);
me->set("eff_qi",1);
me->set("jing",1);
me->set("eff_jing",1);
}
if (!me->query_skill("jiuyin-zhengong",1)
&& me->query_temp("hsljn"))
{
me->set_temp("hslj/5",1);
message("channel:chat", "����ɽ�۽�����˵"+me->name() + "�����"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
        me->add("combat_exp",300);
        me->add("potential",100);
}
        destruct(ob);
        return;
}