#include <ansi.h>
inherit NPC;
//inherit F_MASTER;


void create()
{
    set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
        set("long", 
                "�������һ����ĵ���������������������ɫ�Ķ�а��ҩʦ��\n"
                "����һ����ɫ���ۣ�������б����һֻ���\n"
                "��������񳣬������ˬ���������٣�տȻ����\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 51);
    set("int", 50);
    set("con", 56);
    set("dex", 50);
        set_temp("no_kill",1);
    set("chat_chance", 1);
    set("chat_msg", ({
        "��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
        "��ҩʦ��ͷ��˼����Ȼ���\n",
    }));
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
         set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);

    set("qi", 16000);
    set("max_qi", 16000);
    set("jing", 16000);
    set("max_jing", 16000);
    set("neili", 43500);
    set("max_neili", 43500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 5500000);

	 
    set_skill("leg", 500);             // �����ڹ�
    set_skill("force", 500);             // �����ڹ�
    set_skill("bibo-shengong", 500);     // �̲���
    set_skill("claw", 500);              // ����צ��
    set_skill("hand", 500);              // �����ַ�
    set_skill("finger", 500);            // ����ָ��
    set_skill("tanzhi-shentong", 500);   // ��ָ��ͨ
    set_skill("unarmed", 500);           // ����ȭ��
    set_skill("strike", 500);            // ����ȭ��
    set_skill("luoying-zhang", 500);     // ��Ӣ����
    set_skill("xuanfeng-leg", 500);      // ����ɨҶ��
    set_skill("dodge", 500);             // ��������
    set_skill("anying-fuxiang", 500);    // ��Ӱ����
    set_skill("parry", 500);             // �����м�
    set_skill("sword", 500);             // ��������
    set_skill("luoying-shenjian", 500);  // ��Ӣ��
    set_skill("yuxiao-jian", 500);       // ���｣��
    set_skill("lanhua-shou", 500);       // ������Ѩ��
    set_skill("qimen-wuxing",500);       // ��������
    set_skill("count",500);              // ��������
    set_skill("literate",500);           // ����ʶ��
	
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "yuxiao-jian");
    map_skill("sword"  , "yuxiao-jian");
//	prepare_skill("finger", "tanzhi-shentong");
//	prepare_skill("hand", "lanhua-shou");
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.wuyin" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
//    create_family("�һ���", 1, "����");
    setup();
	
    carry_object("/kungfu/class/taohua/obj/yuxiao")->wield();
    carry_object("/kungfu/class/taohua/obj/bupao")->wear();
//    carry_object("clone/book/jiuyin2");
    
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
me->set_temp("hslj/1",1);
message("channel:chat", "����ɽ�۽�����˵"+me->name() + "�����"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
        me->add("combat_exp",300);
        me->add("potential",100);
}
        destruct(ob);
        return;
}