// xiaozh.c ���л�
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();

void create()
{
        object ob;
        set_name("���л�", ({ "xiao zhonghui", "xiao", "zhonghui"}));
        set("gender", "Ů��");
        set("unique", 1);
        set("age", 20);
        set("long", "
���ǽ�����������͵�Ů��������ò��������ɫ��ɢ����һ�ɲ���Ӣ����\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 3000);
        set("qi", 3000);
        set("jing",1600);
          set("max_jing", 1600);
        set("jingli", 2200);
        set("eff_jingli", 2200);        
        set("neili", 4500);
        set("max_neili", 4500);
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

        set("inquiry", ([
            "̫������" : "�����ĸ����˵�꣬�Ѿ�Ц���������ˡ�\n",
            "Ԭ����" : "����ʶԬ��磿Ԭ������������˵�꣬��৵غ���������\n",
            "�����" : "�������Ͼ�Ҫ����ʮ�����ˣ����˺ܶ�Ӣ�����ء�������\n",
//          "���޵���"  : (: ask_yyd :),
        ]));

        set("chat_chance", 3);
        set("chat_msg", ({
            "���лۺ�Ȼ�������Σ�����������������������̨��������״�ɽ��ݡ���\n",
            "���л۵���˵��������������ǵ������ٵ��ˣ�����ʲô�����أ���\n", 
        }) );

        setup();
        if (clonep()) {
                ob = new(__DIR__"obj/yang");
                if (random(4)==0) ob = new("/clone/weapon/gangdao");
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/red-cloth")->wear();

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
        command("blush");
        return "����޵������ǵ���ʦĸ�����ҵġ�\n";
}
*/
