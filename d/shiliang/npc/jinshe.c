// Feb. 6, 1999 by Winder
// jinshe.c �����ɾ�
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void dest(object ob);

void create()
{
	set_name("��ѩ��", ({"xia xueyi", "xia", "xueyi"}));
	set("nickname", HIY"�����ɾ�"NOR);
	set("gender", "����");
	set("age", 25);
	set("long", 
		"�������˳ơ������ɾ�����һ���ֽܡ�����ѩ�ˡ�\n"
		"������ȫƾ�ö�ʱ��ʱа���˵��Ƕ����������ò�������\n"
		"��˵���������ܲң���Ҳ���ƫ��������\n"
		"���������������˵��ˣ���ɫ���ѿ���\n");
 	set("attitude", "peaceful");
	
	set("str", 100);
	set("int", 30);
	set("con", 30);
	set("dex", 135);
	set("chat_chance", 15);
	set("chat_msg", ({
		"��ѩ��ͻȻ��ݺݵ�˵�����Ƕ����㵽��ΪʲôҪ���ң���\n",
		"��ѩ�����з·�Ҫ���������\n",
                "ͻȻ����ѩ�ˡ��ۡ���һ�����³�һ��ڴ��ڵ�Ѫ��\n",
	}));
	set("inquiry", ([
		"����": "��....��..... \n",
	]));
	set("qi", 100000);
	set("max_qi", 100000);
	set("jing", 50000);
	set("max_jing", 50000);
	set("neili", 90000);
	set("max_neili", 90000);
	set("jiali", 100);
	set("no_get",1);
	
	set("combat_exp", 50000000);
	 
	set_skill("force", 300);		// �����ڹ�
	set_skill("huntian-qigong", 300);	// ��������
	set_skill("unarmed", 320);		// ����ȭ��
	set_skill("dodge", 300);		// ��������
	set_skill("parry", 300);		// �����м�
        set_skill("sword", 300);                // ��������
        set_skill("jinshe-jian",400);           // ���߽���
	
	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("parry", "jinshe-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),                
                (: perform_action, "sword.kun" :),                
                (: perform_action, "sword.shi" :),                
                (: perform_action, "sword.suo" :),                
                (: perform_action, "sword.wan" :),                
        }) );
	set_temp("apply/attack",  250);
	set_temp("apply/defense", 250);        	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
int accept_object(object who, object ob)
{
	object obn;
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");
	if (  (string)ob->query("id") != "wen shoupa")
		    return notify_fail("��ѩ�˲���Ҫ���������\n");
         write(HIY "��ѩ�˽ӹ������������س���ͻȻ����Ȼ���¡� \n" NOR);
         write(HIR "��ѩ���૵����Ƕ�������֪��������⣬��ʵ��������ģ���Ҳ���ں��ġ�\n" NOR);         
         write(HIY "��ѩ��ת��ͷ������˵���Ҹ�������л���أ�\n" NOR);
         write(HIY "����ת��ȥ����Ĭ���������˼����ʲô��\n" NOR);
         write(HIY "��ѩ��ͻȻ�����˺ܴ�����Ƶض���˵���ҿ�\n" NOR);
         write(HIY "��Ҳ���������ˣ������������ұ�����Ѫ�ġ�������ܸ����\n" NOR);
         write(HIY "������������˵�Ѿ�û��ʲô���ˣ������ȥ�ɡ�\n" NOR);
         write(HIY "��ѩ��̾�˿����������ǳ�������Ҳ�ã���������Ҳ�ã�������ΪҲ�ã�ͨͨ�����޹ء�\n" NOR);
         write(HIY "��ѩ�˻��˻��֣����ˣ���������ˡ�\n" NOR);
         obn = new("/clone/book/jinshe2");
         obn->move(who);
         obn = new("/clone/book/jinshe3");
         obn->move(who);
         write(HIR "��ѩ�˻��װ���ǽ�ϵ�һ�����أ�ֻ����¡¡�������죬ʯ��֮��¶��һ���ķ��Ķ�������\n"NOR);
         "/d/shiliang/jinshedong"->set("exits/east","/d/shiliang/jinshedong1");
         destruct(ob);
         return 1;
}
void dest(object ob)
{
    destruct(ob);
}
