#include <ansi.h>
inherit NPC;
int ask_fail();
void create()
{
    set_name(HIY"�����ʵ�"NOR,({"kang xi"}));
    set("gender","����");
    set_temp("no_kill",1);
    set("qi",1000000);
    set("eff_qi",1000000);
    set("max_qi",1000000);
set("jing",1000000);
    set("eff_jing",1000000);
       set("inquiry", ([
                "���������" : (: ask_fail() :),
                "��ʮ���¾�" : (: ask_fail() :),
       ]) );

    setup();
carry_object(__DIR__"obj/longpao")->wear();
}
void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط��ֿ����ʵ۸����������ս����\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "�����ʵ�Ц��˵���������û���ã�\n");
	command("hehe");
}

void die()
{
	unconcious();
}


int ask_fail()
{
        object me = this_player(),obn;
if (random(3)==0)
this_object()->set("alr",1);
        
if (this_object()->query("alr"))
{
                command("say �Ѿ������ҵ������ˣ�");
                return 1;
                }
        if (me->query("huanggong/haspi1") != 1) {
                command("say ��ʮ���¾�һ�����ҵ�����");
                return 1;
                }
        if (me->query("huanggong/haspi2") != 1) {
                command("say ��ʮ���¾��������ҵ�����");
                return 1;
                }
        if (me->query("huanggong/haspi3") != 1) {
                command("say ��ʮ���¾��������ҵ�����");
                return 1;
                }
        if (me->query("huanggong/haspi4") != 1) {
                command("say ��ʮ���¾��ģ����ҵ�����");
                return 1;
                }
        if (me->query("huanggong/haspi5") != 1) {
                command("say ��ʮ���¾��壬���ҵ�����");
                return 1;
                }
        if (me->query("huanggong/haspi6") != 1) {
                command("say ��ʮ���¾��������ҵ�����");
                return 1;
                }
        if (me->query("huanggong/haspi7") != 1) {
                command("say ��ʮ���¾��ߣ����ҵ�����");
                return 1;
                }
        if (me->query("huanggong/haspi8") != 1) {
                command("say ��ʮ���¾��ˣ����ҵ�����");
                return 1;
                }
obn = new(__DIR__"obj/baotu");
obn->move(me);
command("say ��Ȼ��֪���˱��ص�λ��,��Ҫ�úñ�����ݴ��������ͼ!");
command("say ��Ҫ����ݱ��أ����츣�Ҵ�������!");
command("chat ������" + me->query("name") + "���������ͼ��������Ϊ�������!");
this_object()->set("alr",1);
return 1;
}
