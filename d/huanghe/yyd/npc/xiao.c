// xiao.c �����
// zly 99.6.11

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����", ({"xiao banhe", "banhe", "xiao"}));
        set("gender", "����");
        set("title", HIY"��������"NOR);
        set("shen_type", 1);
        set("age", 50);
        set("long", 
"���������֪���Ľ�����������ͣ���������ΰ��������룬����
��ӣ��������䡣\n"
        );
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 2000);
        set("qi", 2000);
        set("max_jing", 2000);
        set("jing",2000);
        set("jingli", 1800);
        set("eff_jing", 1800);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);

        set("combat_exp", 1000000);
        
        set_skill("force", 180);             // �����ڹ�
        set_skill("huntian-qigong", 180);    // ��������
        set_skill("strike", 180);            // �����Ʒ�
        set_skill("xianglong-zhang", 180);   // ����ʮ����
        set_skill("dodge", 180);             // ��������
        set_skill("xiaoyaoyou", 180);        // ��ң��
        set_skill("parry", 180);             // �����м�
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");

        set("chat_chance", 3);
        set("chat_msg", ({
            "��������һ����˵������������Щ�����ӱ����õ�ԧ�쵶����\n",
            "�����̾��һ������˵�����������Ů��ѽ�����ǵ�Ƥ����֪����һ���ܲ��ܸĸġ���\n", 
        }) );

        set("inquiry", ([
        "ԧ�쵶" : "��˵������������޵е����ܡ�\n",
        "���л�" : "�����ҵĹ�Ů�������������������أ�˵�꣬�Ǻǵ�Ц��������\n",
        "Ԭ����" : "�����ҵĹ�Ů����˵�꣬¶�������Ц�ݡ�\n",
        "̫������" : "�������ڰ�æ���ź�ɽ�أ�����ʲô������\n",
        ]));

        setup();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",2);
}

