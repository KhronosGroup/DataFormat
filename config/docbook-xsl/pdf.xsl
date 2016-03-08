<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:param name="pdf.stylesheet" select="'config/df-xhtml.css'"/>
<xsl:template match="address|literallayout[@class!='monospaced']">
  <xsl:text>\begin{alltt}</xsl:text>
  <xsl:text>&#10;\normalfont{}&#10;</xsl:text>
  <xsl:apply-templates/>
  <xsl:text>&#10;\end{alltt}</xsl:text>
</xsl:template>

<xsl:template match="processing-instruction('asciidoc-pagebreak')">
  <!-- force hard pagebreak, varies from 0(low) to 4(high) -->
  <xsl:text>\pagebreak[4] </xsl:text>
  <xsl:apply-templates />
  <xsl:text>&#10;</xsl:text>
</xsl:template>

<xsl:template match="processing-instruction('asciidoc-br')">
  <xsl:text>\newline&#10;</xsl:text>
</xsl:template>

<xsl:template match="processing-instruction('asciidoc-hr')">
  <!-- draw a 444 pt line (centered) -->
  <xsl:text>\begin{center}&#10; </xsl:text>
  <xsl:text>\line(1,0){444}&#10; </xsl:text>
  <xsl:text>\end{center}&#10; </xsl:text>
</xsl:template>
</xsl:stylesheet>
