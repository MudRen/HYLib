// yuangn.c Ԭ����
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();

void create()
{
        object ob;
        set_name("Ԭ����", ({ "yuan guannan", "yuan", "guannan"}));
        set("gender", "����");
        set("unique", 1);
        set("age", 22);
        set("long", "����һ��Ӣ����������������������ҡ�����ȡ�\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 4000);
        set("qi", 4000);
        set("jing",1600);
        set("eff_jing", 1600);
        set("jingli", 2200);
        set("eff_jingli", 2200);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 50);

        set("combat_exp", 1500000);
        
        set_skill("force", 180);             // �����ڹ�
        set_skill("huntian-qigong", 180);    // ��������
        set_skill("blade", 180);             // ��������
        set_skill("wuhu-duanmendao", 190);
//      set_skill("fuqi-daofa", 180);        // ���޵���
        set_skill("dodge", 180);             // �����Ṧ
        set_skill("xiaoyaoyou", 180);        // ��ң��
        set_skill("parry", 180);             // �����м�
        
        map_skill("force", "huntian-qigong");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuhu-duanmendao");

        set("chat_chance", 3);
        set("chat_msg", ({
            "Ԭ���г������������ƽ����ֿ��⾡�������Ʋ���ƶ���ɷ���¿�Х������֪��ȴͷ�Ͻ�......��\n",
            "Ԭ����������������������Ӣ�������½̶��ܣ�������Ʒ��Ψ�ж����......��\n", 
        }) );

        set("inquiry", ([
//           "���޵���"  : (: ask_yyd :),
        ]));

        setup();
        if (clonep()) {
                ob = new(__DIR__"obj/yuan");
                if (random(4)==0) ob = new("/clone/weapon/gangdao");
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",2);
   }
}

/*string ask_yyd()
{
        object me=this_player();
        if(me->query_skill("blade", 1) <120)
                return "���Ȱѵ����Ļ��������˵�ɡ�\n";
        if(me->query("fuqi"))
                return "�ף��㲻���Ѿ�ѧ���˷��޵�������\n";
        if(me->query_temp("mb"))
                return "�ף��Ҳ��ǸղŸ���������\n";
        me->set_temp("mb",1);
        command("hmm");
        command("whisper "+me->query("id")+" ��ʦ��ʦĸ˵�������ǵ����ĸ�ɮԲ���ڼ��ϵ�С���ϡ�");
        return "����޵������ǵ���һλ��ɮ�����ҵ�ʦ���ģ�������������ĺ���������ȥ����λ��ɮ�ɣ�\n";
}
*/
