
inherit NPC;

void create()
{
   set_name("��ؤ",({ "qi gai","qi","gai" }) );
   set("gender", "����" );

   set("long", "����һ����ؤ��������֪��һЩ��Ϣ��\n");
       
   set("combat_exp", 5000);
   set("per",10);
   
   set("inquiry",([
   	"��Ϣ":"�Ǳ��Ĺٱ����������ҵ�Ǯ��������������������һά����һ��ģ�",
   	"����":"����ɣ������ҵĻ����ţ��ҿ����ں���II��Ҳ�첻��ʲô��ͷ�ˣ�"
   	]));
   
   setup();

}
